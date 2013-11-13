#ifndef _CYLINDEROBJ_HH_
#define _CYLINDEROBJ_HH_

#include "SphereObject.hh"
#include "SceneObject.hh"
#include "Ray.hh"
#include <cmath>           

class CylinderObject : public SceneObject {

private:
  Vector3F _center;     //A position value, which specifies the center of the cylinder
  Vector3F _axis;       //specifies the orientation of the cylinder's long axis.
  float _radius;
  float _height;

public:
  // Constructors
  CylinderObject() : SceneObject(), _center(), _axis(), _radius(0), _height(0) {}                  
  CylinderObject(float r, float h, const Vector3F &center, const Vector3F &axis, 
                 const Color &c = default_color, float reflectivity = 0) 
  : SceneObject(c, reflectivity), _center(center) , _axis(axis), _radius(r), _height(h) 
    { _axis.normalize();} 
  
  // Destructor
  ~CylinderObject() {}
  
  Vector3F get_center() const {return _center;}
  float get_radius() const {return _radius;}
  
  //#If an intersection has occurred, the function return the lowest t value for the intersection
  //#If no intersection occurred, return "invalid" value (t = -1)
  float intersection(const Ray &r) const;
  
  //# return the total number of valid intersections (0, 1, or 2)
  //# set t1 and t2 to the t-values of the intersection points, or to your "no intersection" value
  //# When there are two valid intersection points, store the smaller one in t1
  //# When there is only one valid intersection point, always store it in t1, and set t2 to "no intersection"
  //# When there are no valid intersection points, set both t1 and t2 to "no intersection" before returning 0
  int getIntersections(const Ray &r, float &t1, float &t2) const;
  
  //#This function will be used when an intersection occurs
  //#the argument should be a 3D point which is assumed to be on the surface of the object
  //#the return-value is a surface normal for that point
  Vector3F surface_normal(const Vector3F &point) const;
};

SPSceneObject read_Cylinder(std::istream &is);


#endif // _CYLINDEROBJ_HH_
