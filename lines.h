#ifndef LINES_H
#define LINES_H
#include "points.h"
class Lines {
 public :

  Lines(int x1=0,int y1=0,int z1=0,int x2=0,int y2=0,int z2=0,boolean secure=false,boolean exist=false,int r=255,int g=255,int b=255);
  boolean isVisible(VirtualScreen);
  void draw(VirtualScreen);
  void clear(VirtualScreen);
  boolean fexist();
  boolean fsecure();
  void setExist(boolean);
  void setSecure(boolean);
  Points point1;
  Points point2;
 private :
  void drawBase(VirtualScreen);
  
};
#endif
