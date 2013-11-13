#include "PlaneObject.hh"

//#For a ray P + D * t, the intersection point is:
//#    t = -(P · N + d) / (D · N)
float PlaneObject::intersection(const Ray &r) const
{
    float denumerator = r.get_direction() * _surface_normal;
    if(denumerator == 0){
        return -1;
    }
    
    float numerator = (r.get_origin() * _surface_normal) + _dis;
    float t = -numerator / denumerator;
    
    if(t >= 0){
        return t;
    }
    
    return -1;
}

//#  (x, y, z) dist [r, g, b]
SPSceneObject read_Plane(std::istream &is)
{
    SPSceneObject so; 
    if (!is) return so;

    float d;
    Color c;
    Vector3F v;

    is >> v;
    is >> d;
    is >> c;

    if (is){
        so = SPSceneObject(new PlaneObject(v, d));
        so->set_surface_color(c);
    }
    
    return so;
}


