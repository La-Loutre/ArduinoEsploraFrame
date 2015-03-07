#include "drawable.h"


Drawable::Drawable(int x,int y,int z,int r,int g ,int b,boolean exist,boolean secure)
{
  this->x=x;
  this->y=y;
  this->z=z;
  this->r=r;
  this->g=g;
  this->b=b;
  this->exist=exist;
  this->secure=secure;
}
void Drawable::setSecure(boolean a)
{
  this->secure=a;
}
void Drawable::setExist(boolean a)
{
  this->exist=a;

}
boolean Drawable::fsecure()
{
  return this->secure;
}
boolean Drawable::fexist()
{
  return this->exist;
}
