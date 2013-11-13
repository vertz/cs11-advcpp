#include "Light.hh"

//# (x, y, z) [r, g, b]
SPLight read_Light(std::istream &is)
{
    SPLight l; 
    if (!is) return l;

    Color c;
    Vector3F v;

    is >> v;
    is >> c;

    if (is){
        l = SPLight(new Light(v ,c));
    }
    
    return l;
}




