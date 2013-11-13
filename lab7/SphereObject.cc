#include "SphereObject.hh"

//# The surface normal of any point on the sphere is:
//#    n(X) = (X - C) / ||X - C||
Vector3F SphereObject::surface_normal(const Vector3F &point) const
{
    Vector3F ret = point - _center;
    ret.normalize();
    
    return ret;
}

/*
#   a * t² + b * t + c = 0
#
#   a = D · D
#   b = 2 * (P · D - D · C)
#   c = P · P + C · C - 2 * (P · C) - r²
*/
int SphereObject::getIntersections(const Ray &r, float &t1, float &t2) const
{
    t1 = no_intersection;
    t2 = no_intersection;

    float a = dot(r.get_direction() , r.get_direction());
    float b = 2 * (dot(r.get_origin() , r.get_direction()) - dot(r.get_direction() , _center));
    float c = dot(r.get_origin(), r.get_origin()) + dot(_center, _center) - (2 * dot(r.get_origin(), _center)) - pow(_radius, 2.0);
    
    //discriminant
    float dis = pow(b, 2.0) - (4 * a * c);
    if(dis < 0 || a == 0){
        return 0;
    }
    
    dis = sqrt(dis);
    
    float x1 = (-b + dis) / (2 * a);
    float x2 = (-b - dis) / (2 * a);
    
    if(x2 < x1)
    {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }
    
    if(x1 == x2)
    {
        if(x1 < 0){
            return 0;
        }
        
        t1 = x1;
        return 1;
    }
    else // x1 < x2
    {
        if(x2 < 0){      // x1 < x2 < 0
            return 0;
        }
        else if(x1 < 0){ // x1 < 0 < x2
            t1 = x2;
            return 1;
        }
        else{            // 0 <= x1 < x2
            t1 = x1;
            t2 = x2;
            return 2;
        }
    }
    
    return 0;
}

float SphereObject::intersection(const Ray &r) const
{
    // local variables t1, t2 to receive the results
    // of the computation
    float t1, t2;
    this->getIntersections(r, t1, t2);
    
    // t1 is either the closest intersection point, or
    // it is our "no intersection" value.
    return t1;
}

//#  r (x, y, z) [r, g, b] ref
SPSceneObject read_Sphere(std::istream &is)
{
    SPSceneObject so; 
    if (!is) return so;

    float r;
    float ref;
    Color c;
    Vector3F v;

    is >> r;
    is >> v;
    is >> c;
    is >> ref;

    if (is){
        so = SPSceneObject(new SphereObject(r, v, c, ref));
    }
    
    return so;
}



