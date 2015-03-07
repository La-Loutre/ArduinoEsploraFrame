#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <Esplora.h>
#include "virtualScreen.h"
class Drawable{
 public :
  Drawable(int x,int y,int z,int r,int g,int b,boolean exist=false,boolean secure=false);
  virtual boolean isVisible(VirtualScreen)=0;
  virtual void draw(VirtualScreen)=0; // Stroke (color) + draw on screen
  virtual void clear(VirtualScreen)=0;
  boolean fexist();
  boolean fsecure();
  void setExist(boolean);
  void setSecure(boolean);
  int x;
  int y;
  int z;
  int r;
  int g;
  int b;
 protected:
  boolean exist;
  boolean secure;

};

#endif
