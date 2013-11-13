#include "Vector3F.hh"

//Compound assignment ops

float Vector3F::operator()(int i) const
{
    assert(i >= 0 && i < 3); 
    return values[i];
}

float & Vector3F::operator()(int i)
{
    assert(i >= 0 && i < 3); 
    return values[i];
}

Vector3F & Vector3F::operator=( const Vector3F &v)
{
    if (this == &v){
      	return *this;
	}
    
    for(int i=0 ; i < 3 ; ++i)
    {
        values[i] = v.values[i];
    }

	return *this;
}

Vector3F & Vector3F::operator+=(const Vector3F &v)
{
    for(int i=0 ; i < 3 ; ++i){
        values[i] += v.values[i];
    }
    
    return *this;
}

Vector3F & Vector3F::operator-=(const Vector3F &v)
{
    for(int i=0 ; i < 3 ; ++i){
        values[i] -= v.values[i];
    }
    
    return *this;
}

Vector3F & Vector3F::operator*=(float s)
{
    for(int i=0 ; i < 3 ; ++i){
        values[i] *= s;
    }
    
    return *this;
}

Vector3F & Vector3F::operator/=(float s)
{
    assert(s != 0);

    for(int i=0 ; i < 3 ; ++i){
        values[i] /= s;
    }
    
    return *this;
}

//boolean operators

bool Vector3F::operator==(const Vector3F &v) const
{
    return  values[0] == v.values[0] &&
            values[1] == v.values[1] &&
            values[2] == v.values[2];
}

bool Vector3F::operator!=(const Vector3F &v) const
{
    return !(*this == v);
}

//##dot product
float Vector3F::operator*(const Vector3F &v) const
{
    float ret = 0;
    
    for(int i=0 ; i < 3 ; ++i){
        ret += values[i] * v.values[i];
    }
    
    return ret;
}

//##cross-product
Vector3F Vector3F::operator%(const Vector3F &v) const
{
    float x = (values[1] * v.values[2]) - (values[2] * v.values[1]);
    float y = (values[0] * v.values[2]) - (values[2] * v.values[0]);
    float z = (values[0] * v.values[1]) - (values[1] * v.values[0]);

    Vector3F ret (x,y,z);

    return ret;
}

float Vector3F::magnitude() const
{
    return ((*this) * (*this));  
}

float Vector3F::magnitude_squared() const
{
    return sqrtf((*this) * (*this)); 
}

void Vector3F::normalize()
{
    *this /=  this->magnitude_squared();
}

//arithmetic operators
const Vector3F operator+(const Vector3F &v, const Vector3F &u)
{
    Vector3F ret = v;
   	ret += u; 
    return ret;
}

const Vector3F operator-(const Vector3F &v, const Vector3F &u)
{
    Vector3F ret = v;
   	ret -= u; 
    return ret;
}

const Vector3F operator/(const Vector3F &v, float s)
{
    Vector3F ret = v;
    ret /= s; 
    return ret; 
}

const Vector3F operator*(const Vector3F &v, float s)
{
    Vector3F ret = v;
    ret *= s; 
    return ret; 
}

const Vector3F operator*(float s, const Vector3F &v)
{
    Vector3F ret = v;
    ret *= s; 
    return ret; 
}

const Vector3F operator-(const Vector3F &v)
{
    Vector3F ret = v;
    ret *= (-1); 
    return ret; 
}

std::ostream & operator<<(std::ostream &os, const Vector3F &v) 
{ 
    os  << "(" << v(0) << ", " << v(1) << ", " << v(2) << ")"; 
    return os; 
} 

