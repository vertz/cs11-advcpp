#include "PlaneObject.hh"

//#For a ray P + D * t, the intersection point is:
//#    t = -(P · N + d) / (D · N)
float PlaneObject::intersection(const Ray &r) const
{
    float denumerator = dot(r.get_direction() , _normal);
    if(denumerator == 0){
        return no_intersection;
    }
    
    float numerator = dot(r.get_origin(), _normal) + _dis;
    float t = -numerator / denumerator;
    
    if(t >= 0){
        return t;
    }
    
    return no_intersection;
}

//#  dist (x, y, z) [r, g, b] ref
SPSceneObject read_Plane(std::istream &is)
{
    SPSceneObject so; 
    if (!is) return so;

    float d;
    float ref;
    Color c;
    Vector3F v;

    is >> d;
    is >> v;
    is >> c;
    is >> ref;

    if (is){
        so = SPSceneObject(new PlaneObject(d, v, c, ref));
    }
    
    return so;
}


