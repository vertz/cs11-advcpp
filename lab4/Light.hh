#ifndef _LIGHT_HH_
#define _LIGHT_HH_

#include "Vector3F.hh"
#include "Color.hh"

class Light {

private:

  Vector3F _pos; // position
  Color _color;

public:
  // Constructors
  Light() : _pos() , _color() {}                  
  Light(const Vector3F &p, const Color &c) : _pos(p) , _color(c) {}
  
  // Destructor
  ~Light() {}
  
  Vector3F get_position() const {return _pos;}
  Color get_color() const {return _color;}
};

#endif // _LIGHT_HH_
