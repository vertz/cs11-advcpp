#ifndef _SCENEOBJ_HH_
#define _SCENEOBJ_HH_

#include "Vector3F.hh"
#include "Color.hh"
#include "Ray.hh"

#include <boost/shared_ptr.hpp>

const Color default_color(0.5, 0.5, 0.5) ; 
const float no_intersection = -1;

class SceneObject {

private:
  Color _surface_color;
  float _ref; // surface_reflectivity

public:
  // Constructors
  //# initializes surface color to gray               
  SceneObject(const Color &c = default_color, float r = 0) : _surface_color(c), _ref(r) {} 
  
  // Destructor
  virtual ~SceneObject() {}
  
  Color get_surface_color() const {return _surface_color;}
  void set_surface_color(const Color &c) { _surface_color = c;}
  
  float get_surface_reflectivity() {return _ref;}
  
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

//# Define a type for scene-object reader functions 
typedef SPSceneObject (*SceneObjectReader)(std::istream &is);


#endif // _SCENEOBJ_HH_
