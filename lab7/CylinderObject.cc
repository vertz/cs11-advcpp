#include "CylinderObject.hh"

int CylinderObject::getIntersections(const Ray &r, float &t1, float &t2) const
{
    Vector3F c_par = project(_center, _axis);
    Vector3F p_par = project(r.get_origin(), _axis);
    Vector3F d_par = project(r.get_direction(), _axis);

    // Check that ray is capable of hitting cylinder
    if ((r.get_direction() - d_par).magnitude() == 0)
    {
        t1 = no_intersection;
        t2 = no_intersection;
        return 0;
    }

    // Imaginary sphere to test intersections
    SphereObject sph = SphereObject(_radius, _center - c_par);

    // Imaginary ray projected into the cylinder's X-section plane
    // NOT normalized, so that t values transform correctly
    Ray r_proj = Ray(r.get_origin() - p_par, r.get_direction() - d_par, false);

    // Get intersections
    int count = sph.getIntersections(r_proj, t1, t2);

    // Check that intersections are within height of the cylinder
    // Check the 2nd intersection
    if ((count == 2) && ((p_par - c_par + d_par * t2).norm() > _height / 2))
    {
        // Intersection misses height
        t2 = no_intersection;
        --count;
    }

    if ((count >= 1) && ((p_par - c_par + d_par * t1).norm() > _height / 2))
    {
        // Intersection misses height
        t1 = t2;
        t2 = no_intersection;
        --count;
    }

    return count;
}

float CylinderObject::intersection(const Ray &r) const
{
    float t1, t2;

    // Get the intersections
    getIntersections(r, t1, t2);

    // Only care about the first intersection,
    // which will already be flagged if there are none
    return t1;
}

Vector3F CylinderObject::surface_normal(const Vector3F &point) const
{
    // Get vector from center to surface point
    Vector3F offset = point - _center;

    // Remove component along axis
    Vector3F ret = offset - project(offset, _axis);

    // normalize the result
    ret.normalize();
    
    return ret;
}

//#  r h (cx, cy, cz) (ax, ay, az) [r, g, b] ref
SPSceneObject read_Cylinder(std::istream &is)
{
    SPSceneObject so; 
    if (!is) return so;

    float r;
    float h;
    float ref;
    Color c;
    Vector3F v_c;
    Vector3F v_a;

    is >> r;
    is >> h;
    is >> v_c;
    is >> v_a;
    is >> c;
    is >> ref;

    if (is){
        so = SPSceneObject(new CylinderObject(r, h, v_c, v_a, c, ref));
    }
    
    return so;
}
















