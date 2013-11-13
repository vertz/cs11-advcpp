#include "Scene.hh"

void Scene::add_object(SPSceneObject so)
{
    assert(so != NULL); 
    
    _objects.push_back (so);
}

void Scene::add_light(SPLight l)
{
    assert(l != NULL); 
    
    _lights.push_back (l);
}

SPSceneObject Scene::findClosestObject(const Ray &r, float &tIntersect) const
{
    std::vector<SPSceneObject>::const_iterator iter; 
    
    SPSceneObject ret;
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

Color Scene::colorAtPoint(SPSceneObject so, const Vector3F &pIntersect) const
{
    Color retColor(0,0,0);
    
    Vector3F L;
    Vector3F N = so->surface_normal(pIntersect);
    
    std::vector<SPLight>::const_iterator iter; 
    
    for (iter = _lights.begin(); iter != _lights.end(); ++iter) 
    { 
        L = (*iter)->get_position() - pIntersect;
        L.normalize();
        
        retColor += ((*iter)->get_color()) * (so->get_surface_color()) * fmaxf((N * L), 0);
    }
    
    retColor.clamp();
    
    return retColor;
}

Color Scene::traceRay(const Ray &r) const
{
    Color retColor(0,0,0);
    float t;
    
    SPSceneObject so = this->findClosestObject(r, t);
    if(t < 0 || so == NULL){
        return retColor;
    }
    
    Vector3F intersect_loc = r.getPointAtT(t);
    retColor = this->colorAtPoint(so, intersect_loc);
    
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

bool read_Scene(std::istream &is, Scene &scn, Camera &cam)
{
    bool ret = true;

    // Map of type names to SceneObjectReader functions
    std::map<std::string, SceneObjectReader> readFuncs;

    readFuncs["plane"] = read_Plane;
    readFuncs["sphere"] = read_Sphere;
    
    std::string line;
    int ln = 0;
    for (std::getline(is, line); is.good() && ret; std::getline(is, line))
    {
        // Increment line #
        ++ln;

        // Check for comment line
        if (line.length() == 0 || line[0] == '#') continue;

        // Create a string stream to read the line
        std::istringstream iss(line);

        // Read in the next component type
        std::string type;
        iss >> type;

        // Check for empty line
        if (!iss) continue;

        if (readFuncs.find(type) != readFuncs.end())
        {
            // New object to read
            SPSceneObject so;

            // Read object using appropriate function
            so = readFuncs[type](iss);

            if (so == NULL)
            {
                ret = false;
                std::cerr << "Error: Couldn't read " << type << " on line " << ln << std::endl;
            }
            else
            {
                scn.add_object(so);
            }
        }
        else if (type == "light")
        {
            // New light to read
            SPLight l;

            l = read_Light(iss);

            if (l == NULL)
            {
                ret = false;
                std::cerr << "Error: Couldn't read light on line " << ln << std::endl;
            }
            else
            {
                scn.add_light(l);
            }
        }
        else if (type == "camera")
        {
            cam = read_Camera(iss);

            if (!cam.valid())
            {
                ret = false;
                std::cerr << "Error: Couldn't read camera (or invalid camera) on line ";
                std::cerr << ln << std::endl;
            }
        }
        else
        {
            ret = false;
            std::cerr << "Error: Unrecognized type \"" << type << "\" on line " << ln;
            std::cerr << std::endl;
        }
    }
    
    return ret;
}


