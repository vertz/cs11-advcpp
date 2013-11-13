#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "SceneObject.hh"
#include "Vector3F.hh"
#include "Camera.hh"
#include "Color.hh"
#include "Light.hh"
#include "Ray.hh"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>
#include <limits>
#include <cmath>

class Scene {

private:

  std::vector<SPSceneObject> _objects;
  std::vector<SPLight> _lights;
  
  //# helper-function 
  //# takes a ray and returns the closest scene object and time of intersection
  SPSceneObject findClosestObject(const Ray &r, float &tIntersect) const;
  Color colorAtPoint(SPSceneObject so, const Vector3F &pIntersect) const;

public:
  // Constructors
  Scene() : _objects() , _lights() {}                  
  
  // Destructor
  ~Scene() {}
  
  void add_object(SPSceneObject so);
  void add_light(SPLight l);
  
  //# traces a ray in the scene to see what the color for that ray should be
  Color traceRay(const Ray &r) const;
  
  void render(std::ostream &os, const Camera &cam, int imgSize) const;
};





#endif // _SCENE_HH_
