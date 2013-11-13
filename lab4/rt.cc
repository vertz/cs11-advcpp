#include "Vector3F.hh"
#include "Color.hh"

#include "SphereObject.hh"
#include "PlaneObject.hh"
#include "SceneObject.hh"
#include "Camera.hh"
#include "Scene.hh"
#include "Light.hh"


int main()
{
    Scene sc;
    
    SceneObject *pObj = 0;
    Light *pL = 0;
    
    //A plane through the origin: distance = 0, surface normal = (0, 1, 0). 
    //Set its color to [0.5, 0, 0.5], or purple.
    
    Vector3F normal(0, 1, 0);
    Color c1(0.5, 0, 0.5);
    
    pObj = new PlaneObject(normal, 0);
    pObj->set_surface_color(c1);
    sc.add_object(pObj);
    
    //A sphere with center (-1.2, 0.5, 0) and radius 0.5. 
    //Set its color to red [1, 0, 0].
    
    Vector3F center1(-1.2, 0.5, 0);
    Color c2(1, 0, 0);
    
    pObj = new SphereObject(center1, 0.5);
    pObj->set_surface_color(c2);
    sc.add_object(pObj);
    
    //A sphere with center (0, 0.5, 0) and radius 0.5. 
    //Set its color to green [0, 1, 0].
    
    Vector3F center2(0, 0.5, 0);
    Color c3(0, 1, 0);
    
    pObj = new SphereObject(center2, 0.5);
    pObj->set_surface_color(c3);
    sc.add_object(pObj);
    
    //A sphere with center (1.2, 0.5, 0) and radius 0.5. 
    //Set its color to blue [0, 0, 1].
    
    Vector3F center3(1.2, 0.5, 0);
    Color c4(0, 0, 1);
    
    pObj = new SphereObject(center3, 0.5);
    pObj->set_surface_color(c4);
    sc.add_object(pObj);
    
    //Add a light at position (-10, 10, 5) with color [0.8, 0.8, 0.8].
    
    Vector3F pos1(-10, 10, 5);
    Color c5(0.8, 0.8, 0.8);
    
    pL = new Light(pos1, c5);
    sc.add_light(pL);
    
    //Add a light at position ( 5, 3, 5) with color [0.3, 0.3, 0.3].
    
    Vector3F pos2(5, 3, 5);
    Color c6(0.3, 0.3, 0.3);
    
    pL = new Light(pos2, c6);
    sc.add_light(pL);
    
    //configure the camera with these parameters:
    //Camera position: (-1.5, 1, 3)
    //Look at position: (-0.3, 0.5, 0)
    //Up vector: (0, 1, 0)
    
    Vector3F pos(-1.5, 1, 3);
    Vector3F look_at(-0.3, 0.5, 0);
    Vector3F up(0, 1, 0);
    
    Camera cam(pos, look_at, up);
    
    sc.render(std::cout, cam, 500);

    return 0;
}
