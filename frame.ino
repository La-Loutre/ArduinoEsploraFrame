#include "frame.h"

#define BACKGROUND_COLOR_R 0
#define BACKGROUND_COLOR_G 0
#define BACKGROUND_COLOR_B 0
Frame::Frame(int x,int y)
{		
  largeur=x;

  hauteur=y;
  currentScreen=-1;
  for(int i=0;i<NB_MAX_POINTS;i++)
    {
      existPoint[i]=false;
    }
  for(int i=0;i<NB_MAX_VIRTUAL_SCREEN;i++)
    {
      existVirtualScreen[i]=false;
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
int Frame::drawPoint(int x,int y,int r,int g, int b)
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
	  return i;
	}
    }
  
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

 }
}
void Frame::clearPoint(int id)
{
  if(currentScreen!=-1){
     VirtualScreen v=virtualsScreen[currentScreen];
    EsploraTFT.stroke(BACKGROUND_COLOR_R,BACKGROUND_COLOR_G,BACKGROUND_COLOR_B);
    if(existPoint[id]&&pointsIsInVirtualScreen(points[id],v)){
	EsploraTFT.point(points[id].x-v.posX,points[id].y-v.posY);

    }
  }
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
boolean Frame::pointsIsInVirtualScreen(Points p,VirtualScreen v)
{
  if(p.x>v.posX && p.x < v.posX+v.width && p.y > v.posY && p.y < v.posY+v.heigth)
    {
      return true;
    }
  return false;
}
void Frame::drawRectangle(int x, int y,int largeur ,int hauteur)
{
  for(int x1=x;x1<largeur+x;x1++)
    {
      drawPoint(x1,y);
      drawPoint(x1,y+hauteur);
    }
    for(int y1=y;y1<hauteur+y;y1++)
    {
      drawPoint(x,y1);
      drawPoint(x+largeur,y1);
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

	  Serial.println(i);
	  if(pointsIsInVirtualScreen(points[i],v)){
	    
	    EsploraTFT.stroke(points[i].r,points[i].g,points[i].b);
	  
	    EsploraTFT.point(points[i].x-v.posX,points[i].y-v.posY);
	  }
	}
    }
  }
}
