#include "Vector3F.hh"
#include "Color.hh"

#include "SphereObject.hh"
#include "PlaneObject.hh"
#include "SceneObject.hh"
#include "Camera.hh"
#include "Scene.hh"
#include "Light.hh"

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    Scene scn;
    Camera cam;
    
    bool fd = false;
    
    std::ifstream f;
    if (argc > 2 && argv[1][0] == '-' &&  argv[1][1] == 'f')
    {
        f.open(argv[2]);
        fd = true;
        
        if(f.fail())
        {
            std::cerr << "couldn't open the file (\"" << argv[2] << "\")" << std::endl;
            return -1;
        }
    }
    
    std::istream &in = fd ? f : std::cin;
    
    if(!read_Scene(in, scn, cam))
    {
        std::cerr << "Parsing of scene description failed." << std::endl;
    }
    else
    {
        // Render the scene to std out
        scn.render(std::cout, cam, 500);
    }
    
    if(fd) f.close();

    return 0;
}
