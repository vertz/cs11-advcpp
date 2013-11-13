#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "SceneObject.hh"
#include "Light.hh"

#include <algorithm>
#include <iterator>
#include <cassert>
#include <vector>

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
};

#endif // _SCENE_HH_
