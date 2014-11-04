#include "lines.h"

Lines::Lines(int x1,int y1,int x2,int y2,boolean secure,boolean exist,int r,int g ,int b)
{
  this->x1=x1;
  this->y1=y1;
  this->x2=x2;
  this->y2=y2;
  this->r=r;
  this->g=g;
  this->b=b;
  this->exist=exist;
  this->secure=secure;
}
