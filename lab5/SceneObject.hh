#ifndef _SCENEOBJ_HH_
#define _SCENEOBJ_HH_

#include "Vector3F.hh"
#include "Color.hh"
#include "Ray.hh"

#include <boost/shared_ptr.hpp>

class SceneObject {

private:
  Color _surface_color;

public:
  // Constructors
  //# initializes surface color to gray
  SceneObject() : _surface_color(0.5, 0.5, 0.5) {}                  
  SceneObject(const Color &c) : _surface_color(c) {} 
  
  // Destructor
  virtual ~SceneObject() {}
  
  Color get_surface_color() const {return _surface_color;}
  void set_surface_color(const Color &c) { _surface_color = c;}
  
  //#If an intersection has occurred, the function return the lowest t value for the intersection
  //#If no intersection occurred, return "invalid" value (t = -1)
  virtual float intersection(const Ray &r) const = 0;
  
  //#This function will be used when an intersection occurs
  //#the argument should be a 3D point which is assumed to be on the surface of the object
  //#the return-value is a surface normal for that point
  virtual Vector3F surface_normal(const Vector3F &point) const = 0;
  
  //#returns the color of a point on an object
  //#argument a 3D point on the surface of the object
  virtual Color point_color(const Vector3F &point) {return _surface_color;}
};

//# Boost Shared Pointer for SceneObject
typedef boost::shared_ptr<SceneObject> SPSceneObject;


#endif // _SCENEOBJ_HH_
