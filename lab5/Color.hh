#ifndef _COLOR_HH_
#define _COLOR_HH_

#include <algorithm>
#include <iostream>
#include <cassert>

class Color {

private:

  float _red;
  float _green;
  float _blue;

public:
  // Constructors
  Color() : _red(0), _green(0), _blue(0) {}                  
  Color(float r, float g, float b) : _red(r), _green(g), _blue(b) {} 
  Color(const Color &rhs) : _red(rhs._red), _green(rhs._green), _blue(rhs._blue) {} 
  
  // Destructor
  ~Color() {}
  
  float get_red()   const {return _red;}
  float get_green() const {return _green;}
  float get_blue()  const {return _blue;}
  
  void set_red(float val)   { _red = val;}
  void set_green(float val) { _green = val;}
  void set_blue(float val)  { _blue = val;}
  
  void clamp();
  
  //Compound assignment ops
  Color & operator=(const Color &rhs);
  
  Color & operator+=(const Color &rhs);
  Color & operator-=(const Color &rhs);
  Color & operator*=(const Color &rhs);
  
  Color & operator*=(float s);
  Color & operator/=(float s);
};

//arithmetic operators
const Color operator*(const Color &lhs, const Color &rhs);
const Color operator+(const Color &lhs, const Color &rhs);
const Color operator-(const Color &lhs, const Color &rhs);
const Color operator/(const Color &lhs, float s);
const Color operator*(const Color &lhs, float s); 
const Color operator*(float s, const Color &rhs);

std::ostream & operator<<(std::ostream &os, const Color &rhs);

#endif // _COLOR_HH_



