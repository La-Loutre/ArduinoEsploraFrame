#include "frame.h"
#ifndef BACKGROUND_COLOR_R
#define BACKGROUND_COLOR_R 0
#define BACKGROUND_COLOR_G 0
#define BACKGROUND_COLOR_B 0
#endif
Frame::Frame(int x,int y)
{		
  largeur=x;

  hauteur=y;
  currentScreen=-1;
  for(int i=0;i<NB_MAX_POINTS;i++)
    {
      existPoint[i]=false;
      isSecurePoint[i]=false;
    }
  for(int i=0;i<NB_MAX_VIRTUAL_SCREEN;i++)
    {
      existVirtualScreen[i]=false;
    }
}
void Frame::needSpace(int nb)
{
  int compteur=0;
  for(int i=0;i<NB_MAX_POINTS&&compteur<nb;i++)
    {

      if(existPoint[i]){
	if(clearPoint(i)){
	existPoint[i]=false;

	compteur+=1;
	}
      }
    }
}
void Frame::addVirtualScreen(int largeur,int hauteur,int x,int y)
{
  for(int i=0;i<NB_MAX_VIRTUAL_SCREEN;i++)
    {
      if(!existVirtualScreen[i])
	{
	  existVirtualScreen[i]=true;
	  virtualsScreen[i].posX=x;
	  virtualsScreen[i].posY=y;
	  virtualsScreen[i].heigth=hauteur;
	  virtualsScreen[i].width=largeur;
	  if(currentScreen==-1)
	    {
	      currentScreen=i;
	    }
	  break;
	}
    }
}
void Frame::setVirtualScreen(int numero)
{
  //Pas de vérification pour le moment.
  clearScreen(currentScreen);
  currentScreen=numero;
  
}
int Frame::getNbOfVirtualScreen()
{
  int compteur=0;
  for(int i=0;i<NB_MAX_VIRTUAL_SCREEN;i++)
    {
      if(existVirtualScreen[i])
	compteur++;
    }
  return compteur;
}

int Frame::getNbOfCurrentVirtualScreen()
{
  return currentScreen;
}
int Frame::addLine(int x1,int y1,int x2,int y2,boolean secure,int r,int g,int b)
{
  for(int i=0;i<NB_MAX_LINES;i++)
    {
      if(!lines[i].fexist())
	{
	  Lines tmp(x1,y1,x2,y2,secure,true,r,g,b);
	  lines[i]=Lines(x1,y1,x2,y2,secure,true,r,g,b);
	  break;
	}

    }

}
int Frame::addPoint(int x,int y,boolean secure,int r,int g, int b)
{
  for(int i=0;i<NB_MAX_POINTS;i++)
    {
      if(!existPoint[i])
	{
	  points[i].x=x;
	  points[i].y=y;
	  points[i].r=r;
	  points[i].g=g;
	  points[i].b=b;
	  existPoint[i]=true;
	  isSecurePoint[i]=secure;
	  return i;
	}
    }
  needSpace();
  
}
void Frame::drawLine(int x1,int y1,int x2,int y2)
{
  int y;
  for(int i=x1;i<x2;i++)

      EsploraTFT.point(i,y);


}
void Frame::clearScreen(int numero)
{
 if(currentScreen!=-1){
  VirtualScreen v=virtualsScreen[currentScreen];
  EsploraTFT.stroke(BACKGROUND_COLOR_R,BACKGROUND_COLOR_G,BACKGROUND_COLOR_B);
  for(int i=0;i<NB_MAX_POINTS;i++)
    {
      if(existPoint[i]&&pointsIsInVirtualScreen(points[i],v)){
	EsploraTFT.point(points[i].x-v.posX,points[i].y-v.posY);
	
      }
      
    }
  for(int i=0;i<NB_MAX_LINES;i++)
    {
      if(lines[i].fexist()&&lineIsInVirtualScreen(lines[i],v)){
	int x1Repare=lines[i].point1.x-v.posX;
	if(x1Repare<0){
	  x1Repare=0;
	}
	lines[i].draw(v);

      }
    }

 }
}
boolean Frame::clearPoint(int id)
{
  if(currentScreen!=-1){
     VirtualScreen v=virtualsScreen[currentScreen];
    EsploraTFT.stroke(BACKGROUND_COLOR_R,BACKGROUND_COLOR_G,BACKGROUND_COLOR_B);
    if(existPoint[id]&&pointsIsInVirtualScreen(points[id],v)){
	EsploraTFT.point(points[id].x-v.posX,points[id].y-v.posY);
	return true;
    }
    
  }
  return false;
}
int Frame::getPointPositionX(int id)
{
  return points[id].x; 
}
int Frame::getPointPositionY(int id)
{
  return points[id].y; 
}
void Frame::movePoint(int id,int addx,int addy)
{
  if(existPoint[id])
    {
      clearPoint(id);
      points[id].x+=addx;
      points[id].y+=addy;
      drawCurrentScreen();
    }
}
void Frame::moveScreen(int numeroScreen,int x,int y,boolean draw)
{
  clearScreen(numeroScreen);
  virtualsScreen[numeroScreen].posX+=x;
  virtualsScreen[numeroScreen].posY+=y;
  
  if(numeroScreen==currentScreen && draw)
    drawCurrentScreen();
}
boolean Frame::lineIsInVirtualScreen(Lines l,VirtualScreen v)
{
  Points tmp,tmp2;
  tmp.x=l.point1.x;
  tmp.y=l.point1.y;
  tmp2.x=l.point2.x;
  tmp2.y=l.point2.y;
  if(pointsIsInVirtualScreen(tmp,v)||pointsIsInVirtualScreen(tmp2,v)){
    return true;
  }
  return false;

}
boolean Frame::pointsIsInVirtualScreen(Points p,VirtualScreen v)
{
  if(p.x>v.posX && p.x < v.posX+v.width && p.y > v.posY && p.y < v.posY+v.heigth)
    {
      return true;
    }
  return false;
}
void Frame::addRectangle(int x, int y,int largeur ,int hauteur,boolean secure)
{
  for(int x1=x;x1<largeur+x;x1++)
    {
      addPoint(x1,y,secure);
      addPoint(x1,y+hauteur,secure);
    }
    for(int y1=y;y1<hauteur+y;y1++)
    {
      addPoint(x,y1,secure);
      addPoint(x+largeur,y1,secure);
    }
}
void Frame::drawCurrentScreen()
{
 
  if(currentScreen!=-1){
  VirtualScreen v=virtualsScreen[currentScreen];
  for(int i=0;i<NB_MAX_POINTS;i++)
    {
      	 
      if(existPoint[i])
	{


	  if(pointsIsInVirtualScreen(points[i],v)){
	    
	    EsploraTFT.stroke(points[i].r,points[i].g,points[i].b);
	  
	    EsploraTFT.point(points[i].x-v.posX,points[i].y-v.posY);
	  }
	}
    }
  for(int i=0;i<NB_MAX_LINES;i++)
    {
     
      if(lines[i].fexist()){
	  
      	if(lineIsInVirtualScreen(lines[i],v)){
	  lines[i].draw(v);

       }

    }
  }
  }}
