#include "lines.h"
#include "virtualScreen.h"
#ifndef BACKGROUND_COLOR_R
#define BACKGROUND_COLOR_R 0
#define BACKGROUND_COLOR_G 0
#define BACKGROUND_COLOR_B 0
#endif


Lines::Lines(int x1,int y1,int z1,int x2,int y2,int z2,boolean secure,boolean exist,int r,int g ,int b)
{
  point1=Points(x1,y1,z1,r,g,b);
  point2=Points(x2,y2,z2,r,g,b);
}


boolean Lines::isVisible(VirtualScreen v)
{
  if(point1.isVisible(v)||point2.isVisible(v))
    return true;
  return false;
}
void Lines::setSecure(boolean a)
{
  point1.setSecure(a);
  point2.setSecure(a);
}
void Lines::setExist(boolean a)
{
  point1.setExist(a);
  point2.setExist(a);
}
boolean Lines::fsecure()
{
  return point1.fsecure()&&point2.fsecure();

}
boolean Lines::fexist()
{
  return point1.fexist()&&point2.fexist();
}
void Lines::drawBase(VirtualScreen v)
{
  /*
    Correction du bug lorsque x1 < 0 et ligne horizontale
  */
  int x1Repare=point1.x-v.posX;
  if(x1Repare<0){
    x1Repare=0;
  }
  int x1,y1,x2,y2;
  x1=point1.x-v.posX;
  y1=point1.y-v.posY;
  x2=point2.x-v.posX;
  y2=point2.y-v.posY;
  
  int y;
  for(int i=x1;i<x2;i++)

      EsploraTFT.point(i,y);
  


}
void Lines::clear(VirtualScreen v)
{
  EsploraTFT.stroke(BACKGROUND_COLOR_R,BACKGROUND_COLOR_G,BACKGROUND_COLOR_B);
  drawBase(v);
}
void Lines::draw(VirtualScreen v)
{

  EsploraTFT.stroke(point1.r,point1.g,point1.b);
  drawBase(v);
}

