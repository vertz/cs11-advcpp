#include "Ray.hh"

Ray::Ray(const Vector3F &orig, const Vector3F &dir, bool normalize) :
    _orig(orig) , _dir(dir)
{
    if(normalize){
        _dir.normalize();
    }
}

Vector3F Ray::getPointAtT(float t) const
{
    assert(t >= 0);
    
    Vector3F ret = _orig + (_dir * t);
    
    return ret;
}









