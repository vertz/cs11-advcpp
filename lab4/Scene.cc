#include "Scene.hh"

void Scene::add_object(SceneObject *pObj)
{
    assert(pObj != 0); 
    
    _objects.push_back (pObj);
}

void Scene::add_light(Light *pL)
{
    assert(pL != 0); 
    
    _lights.push_back (pL);
}

SceneObject * Scene::findClosestObject(const Ray &r, float &tIntersect) const
{
    std::vector<SceneObject*>::const_iterator iter; 
    
    SceneObject* ret = 0;
    float t;
    float min = std::numeric_limits<float>::max();
    
    for (iter = _objects.begin(); iter != _objects.end(); ++iter) 
    { 
        t = (*iter)->intersection(r);
        
        if (t >= 0 && t < min)
        {
            min = t;
            ret = *iter;
        }
    }
    
    tIntersect = ret != 0 ? min : -1;
    
    return ret;
}

Color Scene::colorAtPoint(SceneObject *obj, const Vector3F &pIntersect) const
{
    Color retColor(0,0,0);
    
    Vector3F L;
    Vector3F N = obj->surface_normal(pIntersect);
    
    std::vector<Light*>::const_iterator iter; 
    
    for (iter = _lights.begin(); iter != _lights.end(); ++iter) 
    { 
        L = (*iter)->get_position() - pIntersect;
        L.normalize();
        
        retColor += ((*iter)->get_color()) * (obj->get_surface_color()) * fmaxf((N * L), 0);
    }
    
    retColor.clamp();
    
    return retColor;
}

Color Scene::traceRay(const Ray &r) const
{
    Color retColor(0,0,0);
    float t;
    
    SceneObject* obj = this->findClosestObject(r, t);
    if(t < 0 || obj == 0){
        return retColor;
    }
    
    Vector3F intersect_loc = r.getPointAtT(t);
    retColor = this->colorAtPoint(obj, intersect_loc);
    
    return retColor;
}

void Scene::render(std::ostream &os, const Camera &cam, int imgSize) const
{
    static int maxval = 255;

    //P3 width height maxval
    os << "P3 " 
       << imgSize << " "
       << imgSize << " "
       << maxval   << std::endl ; 
    
    for (int y = 0; y < imgSize; y++){
        for (int x = 0; x < imgSize; x++)
        {
            Ray pixelRay = cam.getRayForPixel(x, y, imgSize);
            Color pixelColor = this->traceRay(pixelRay);
            
            //red_i grn_i blu_i
            os << (int)(pixelColor.get_red()   * maxval) << " " 
               << (int)(pixelColor.get_green() * maxval) << " " 
               << (int)(pixelColor.get_blue()  * maxval) << std::endl;
        }
    }
}




