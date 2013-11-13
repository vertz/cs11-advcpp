#ifndef _PLANEOBJ_HH_
#define _PLANEOBJ_HH_

#include "SceneObject.hh"
#include "Ray.hh"

class PlaneObject : public SceneObject {

private:
  Vector3F _normal; //surface normal
  float _dis;

public:
  // Constructors
  PlaneObject() : SceneObject(), _normal(), _dis(0) {}                  
  PlaneObject(float dis, const Vector3F &normal, const Color &c = default_color, float reflectivity = 0) 
  : SceneObject(c, reflectivity), _normal(normal) , _dis(dis) 
  {_normal.normalize();} 
  
  // Destructor
  ~PlaneObject() {}
  
  Vector3F get_surface_normal() const {return _normal;}
  float get_distance() const {return _dis;}
  
  //#If an intersection has occurred, the function return the lowest t value for the intersection
  //#If no intersection occurred, return "invalid" value (t = -1)
  float intersection(const Ray &r) const;
  
  //#This function will be used when an intersection occurs
  //#the argument should be a 3D point which is assumed to be on the surface of the object
  //#the return-value is a surface normal for that point
  Vector3F surface_normal(const Vector3F &point) const {return _normal;}
};

SPSceneObject read_Plane(std::istream &is);


#endif // _PLANEOBJ_HH_
