#include "points.h"
#include "drawable.h"
#include "virtualScreen.h"
#ifndef BACKGROUND_COLOR_R
#define BACKGROUND_COLOR_R 0
#define BACKGROUND_COLOR_G 0
#define BACKGROUND_COLOR_B 0
#endif
Points::Points(int x,int y,int z,int r,int g,int b):Drawable(x,y,z,r,g,b)
{
  
  
}
void Points::draw(VirtualScreen v)
{
  EsploraTFT.stroke(r,g,b);
  EsploraTFT.point(x-v.posX,y-v.posY);

}
void Points::clear(VirtualScreen v)
{
  EsploraTFT.stroke(BACKGROUND_COLOR_R,BACKGROUND_COLOR_G,BACKGROUND_COLOR_B);
  EsploraTFT.point(x-v.posX,y-v.posY);

}
boolean Points::isVisible(VirtualScreen v)
{
  if(x>v.posX && x < v.posX+v.width && y > v.posY && y < v.posY+v.heigth)
    return true;
  
  return false;
}
