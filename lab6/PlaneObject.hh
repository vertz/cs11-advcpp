#ifndef _PLANEOBJ_HH_
#define _PLANEOBJ_HH_

#include "SceneObject.hh"
#include "Ray.hh"

class PlaneObject : public SceneObject {

private:
  Vector3F _surface_normal;
  float _dis;

public:
  // Constructors
  PlaneObject() : SceneObject(), _surface_normal(), _dis(0) {}                  
  PlaneObject(const Vector3F &normal , float dis) : SceneObject(), _surface_normal(normal) , _dis(dis) 
  {_surface_normal.normalize();} 
  
  // Destructor
  ~PlaneObject() {}
  
  Vector3F get_surface_normal() const {return _surface_normal;}
  float get_distance() const {return _dis;}
  
  //#If an intersection has occurred, the function return the lowest t value for the intersection
  //#If no intersection occurred, return "invalid" value (t = -1)
  float intersection(const Ray &r) const;
  
  //#This function will be used when an intersection occurs
  //#the argument should be a 3D point which is assumed to be on the surface of the object
  //#the return-value is a surface normal for that point
  Vector3F surface_normal(const Vector3F &point) const {return _surface_normal;}
};

SPSceneObject read_Plane(std::istream &is);


#endif // _PLANEOBJ_HH_
