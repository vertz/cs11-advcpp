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

  std::vector<SceneObject*> _objects;
  std::vector<Light*> _lights;
  
  struct DeleteObject 
  { 
    template<typename T> 
    void operator()(const T *ptr) const 
    { 
        delete ptr; 
    } 
  };
  
  //# helper-function 
  //# takes a ray and returns the closest scene object and time of intersection
  SceneObject * findClosestObject(const Ray &r, float &tIntersect) const;
  Color colorAtPoint(SceneObject *obj, const Vector3F &pIntersect) const;

public:
  // Constructors
  Scene() : _objects() , _lights() {}                  
  
  // Destructor
  ~Scene() 
  {
        for_each(_objects.begin(), _objects.end(), DeleteObject());
        for_each(_lights.begin() , _lights.end() , DeleteObject());
  }
  
  void add_object(SceneObject *pObj);
  void add_light(Light *pL);
  
  //# traces a ray in the scene to see what the color for that ray should be
  Color traceRay(const Ray &r) const;
  
  void render(std::ostream &os, const Camera &cam, int imgSize) const;
};





#endif // _SCENE_HH_
