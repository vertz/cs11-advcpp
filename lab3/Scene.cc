#include "Scene.hh"

void Scene::add_object(SceneObject *pObj)
{
    assert(pObj != 0); 
    
    _objects.push_back (pObj);
}

void Scene::add_light(Light *pL)
{
    assert(pL != 0); 
    
    _lights.push_back (pL);
}
