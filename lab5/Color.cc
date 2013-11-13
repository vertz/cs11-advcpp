#include "Color.hh"

Color & Color::operator=(const Color &rhs)
{
    if (this == &rhs){
      	return *this;
	}
    
    _red   = rhs._red;
    _green = rhs._green;
    _blue  = rhs._blue;

	return *this;
}
  
Color & Color::operator+=(const Color &rhs)
{
    _red   += rhs._red;
    _green += rhs._green;
    _blue  += rhs._blue;
    
    return *this;
}

Color & Color::operator-=(const Color &rhs)
{
    _red   -= rhs._red;
    _green -= rhs._green;
    _blue  -= rhs._blue;
    
    return *this;
}

Color & Color::operator*=(const Color &rhs)
{
    _red   *= rhs._red;
    _green *= rhs._green;
    _blue  *= rhs._blue;
    
    return *this;
}
  
Color & Color::operator*=(float s)
{
    _red   *= s;
    _green *= s;
    _blue  *= s;
    
    return *this;
}

Color & Color::operator/=(float s)
{
    assert(s != 0);

    _red   /= s;
    _green /= s;
    _blue  /= s;
    
    return *this;
}
const Color operator*(const Color &lhs, const Color &rhs)
{
    Color ret = lhs;
   	ret *= rhs; 
    return ret;
}

const Color operator+(const Color &lhs, const Color &rhs)
{
    Color ret = lhs;
   	ret += rhs; 
    return ret;
}

const Color operator-(const Color &lhs, const Color &rhs)
{
    Color ret = lhs;
   	ret -= rhs; 
    return ret;
}

const Color operator/(const Color &lhs, float s)
{
    assert(s != 0);
    
    Color ret = lhs;
   	ret /= s; 
    return ret;
}

const Color operator*(const Color &lhs, float s)
{
    Color ret = lhs;
   	ret *= s; 
    return ret;
}

const Color operator*(float s, const Color &rhs)
{
    Color ret = rhs;
   	ret *= s; 
    return ret;
}

std::ostream & operator<<(std::ostream &os, const Color &rhs)
{ 
    os  << "(" << rhs.get_red() << ", " << rhs.get_green() << ", " << rhs.get_blue() << ")"; 
    return os; 
} 

void Color::clamp()
{
  _red   = (_red   < 0) ? 0 : ((_red   > 1) ? 1 : _red);
  _green = (_green < 0) ? 0 : ((_green > 1) ? 1 : _green);
  _blue  = (_blue  < 0) ? 0 : ((_blue  > 1) ? 1 : _blue);
}




