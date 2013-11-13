#ifndef _VECTOR3F_HH_
#define _VECTOR3F_HH_

#include <initializer_list>
#include <iostream>
#include <cassert>
#include <cmath>

class Vector3F {

private:

  float values[3];

public:
  // Constructors
  Vector3F() : values{0, 0, 0} {}                  
  Vector3F(float x, float y, float z) : values{x, y, z} {} 
  Vector3F(std::initializer_list<float> init);

  // Destructor
  ~Vector3F() {}
  
  float operator[](int i) const; 
  float & operator[](int i);
  
  //Compound assignment ops
  Vector3F & operator=(const Vector3F &v);
  
  Vector3F & operator+=(const Vector3F &v);
  Vector3F & operator-=(const Vector3F &v);
  
  Vector3F & operator*=(float s);
  Vector3F & operator/=(float s);
  
  //boolean operators
  bool operator==(const Vector3F &v) const;
  bool operator!=(const Vector3F &v) const;
  
  float magnitude() const;
  float norm() const;
  
  void normalize();
};

//arithmetic operators
const Vector3F operator+(const Vector3F &v, const Vector3F &u);
const Vector3F operator-(const Vector3F &v, const Vector3F &u);
const Vector3F operator/(const Vector3F &v, float s); 
const Vector3F operator*(const Vector3F &v, float s); 
const Vector3F operator*(float s, const Vector3F &v);
const Vector3F operator-(const Vector3F &v);

//##dot-product
float dot(const Vector3F &v, const Vector3F &u);

//##cross-product
const Vector3F cross(const Vector3F &v, const Vector3F &u);

//##project v into u
const Vector3F project(const Vector3F &v, const Vector3F &u);

std::ostream & operator<<(std::ostream &os, const Vector3F &v);
std::istream & operator>>(std::istream &is, Vector3F &v);

#endif // _VECTOR3F_HH_
