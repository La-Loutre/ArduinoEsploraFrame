#ifndef POINTS_H
#define POINTS_H
#include "drawable.h"
#include "virtualScreen.h"
class Points : public Drawable
{
public:
  Points(int x=0,int y=0,int z=0,int r=255,int g=255,int b=255);
  void draw(VirtualScreen);
  void clear(VirtualScreen);
  boolean isVisible(VirtualScreen);
};


#endif
