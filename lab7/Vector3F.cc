#include "Vector3F.hh"

Vector3F::Vector3F(std::initializer_list<float> init)
{
    assert(init.size() == 3);

    // Iterator over initializer_list
    typename std::initializer_list<float>::iterator it = init.begin();

    for (int i = 0; i < 3; ++i, ++it)
    {
        values[i] = *it;
    }
}

//Compound assignment ops

float Vector3F::operator[](int i) const
{
    assert(i >= 0 && i < 3); 
    return values[i];
}

float & Vector3F::operator[](int i)
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
        values[i] = v[i];
    }

	return *this;
}

Vector3F & Vector3F::operator+=(const Vector3F &v)
{
    for(int i=0 ; i < 3 ; ++i){
        values[i] += v[i];
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
    return  values[0] == v[0] &&
            values[1] == v[1] &&
            values[2] == v[2];
}

bool Vector3F::operator!=(const Vector3F &v) const
{
    return !(*this == v);
}

//##dot product
float dot(const Vector3F &v, const Vector3F &u)
{
    float ret = 0;
    
    for(int i=0 ; i < 3 ; ++i){
        ret += v[i] * u[i];
    }
    
    return ret;
}

//##cross-product
const Vector3F cross(const Vector3F &v, const Vector3F &u)
{
    float x = (v[1] * u[2]) - (v[2] * u[1]);
    float y = (v[2] * u[0]) - (v[0] * u[2]);
    float z = (v[0] * u[1]) - (v[1] * u[0]);

    Vector3F ret (x,y,z);

    return ret;
}

//##project v into u
//##project(A, B) = B * ((A · B) / (B · B))
const Vector3F project(const Vector3F &v, const Vector3F &u)
{
    float nu = dot(u,u);
    
    assert(nu != 0);
    
    return ((dot(v,u) / nu) * u);
}

float Vector3F::magnitude() const
{
    return dot((*this) , (*this));  
}

float Vector3F::norm() const
{
    return sqrtf(this->magnitude()); 
}

void Vector3F::normalize()
{
    float norm = this->norm();
    
    if(norm == 0) return;
    
    *this /= norm;
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
    os  << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")"; 
    return os; 
} 

std::istream & operator>>(std::istream &is, Vector3F &v)
{
    float xyz[3];
    int i=0;
    
    char ch;
    
    if(!is)  return is;
    
    is >> ch;
    if(ch != '(')
    {
        is.clear(std::ios_base::failbit);
        return is;
    }
    
    // (x,y,z)
    while(i < 3)
    {
        is >> xyz[i] >> ch;
        ++i;
        
        if((i < 3 && ch != ',') || (i == 3 && ch != ')'))
        {
            is.clear(std::ios_base::failbit);
            return is;
        }
    }
    
    if(is){
        v = Vector3F(xyz[0], xyz[1], xyz[2]);
    }

    return is;
}



