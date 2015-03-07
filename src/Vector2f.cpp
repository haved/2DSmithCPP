#include "Vector2f.h"
#include <cmath>

Vector2f::Vector2f(){}

Vector2f::Vector2f(float x, float y){this->x=x; this->y=y;}

void Vector2f::xy(float x, float y){this->x=x; this->y=y;}

float Vector2f::GetLength()
{
    return sqrt(x*x+y*y);
}

bool Vector2f::IsNull()
{
    return (x == 0.0f) & (y == 0.0f);
}

void Vector2f::Normalize()
{
    float l=GetLength();
    if(l > 0.0f)
    {
        x/=l;
        y/=l;
    }
}

void Vector2f::Multiply(float f)
{
    x *= f;
    y *= f;
}

void Vector2f::Multiply(float x2, float y2)
{
    x *= x2;
    y *= y2;
}

void Vector2f::Multiply(Vector2f v)
{
    x *= v.x;
    y *= v.y;
}

void Vector2f::Add(float x2, float y2)
{
    x += x2;
    y += y2;
}

void Vector2f::Add(Vector2f v)
{
    x += v.x;
    y += v.y;
}

void Vector2f::Divide(float d)
{
    x /= d;
    y /= d;
}

void Vector2f::Divide(float x2, float y2)
{
    x /= x2;
    y /= y2;
}

void Vector2f::Divide(Vector2f v)
{
    x /= v.x;
    y /= v.y;
}
