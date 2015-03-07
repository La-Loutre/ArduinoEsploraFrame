#ifndef FRAME_H
#define FRAME_H
#include "points.h"
#include "virtualScreen.h"
#include "lines.h"
#include <Esplora.h>

#define NB_MAX_POINTS 50
#define NB_MAX_LINES 20
#define BASE_POINT_CLEAR NB_MAX_POINTS/5
#define NB_MAX_VIRTUAL_SCREEN 3
#define DEF_R 255
#define DEF_G 255
#define DEF_B 255
class Frame{
public :
  Frame(int=500,int=500);// x,y
  void addVirtualScreen(int,int,int,int);//TFT largeur ,TFT hauteur , posX , pos Y

  void drawCurrentScreen();
  void setVirtualScreen(int );//numero
  int getNbOfVirtualScreen();
  int getNbOfCurrentVirtualScreen();
  void moveScreen(int,int,int,boolean=true);//numeroScreen , addx,addy ,draw the screen at the end 
  void movePoint(int,int,int);//Id point , addx , addy
  
  int addPoint(int ,int,int,boolean=false,int=DEF_R,int=DEF_G,int=DEF_B);//x ,y,z (frame based),boolean isSecurePoint,r,g,b, renvoie l'id du point 
  int addLine(int ,int,int,int ,int ,int,boolean=false,int=DEF_R,int=DEF_G,int=DEF_B);//x1,y1,x2,y2 etc as point
  boolean pointsIsInVirtualScreen(Points ,VirtualScreen );
  boolean lineIsInVirtualScreen(Lines,VirtualScreen);
  int getPointPositionX(int);//id  du point
  int getPointPositionY(int);//id du point
  
  //Non minimal interface function
  void addRectangle(int,int,int,int,boolean=false);//x,y,largeur,hauteur,secure
 
private:
  void clearScreen(int);//numeroScreen
  void drawLine(int ,int ,int ,int);
  boolean clearPoint(int);//id point , retourne si la suppression à réussi (secure points ne peuvent pas être clear
  void needSpace(int=BASE_POINT_CLEAR); //nb -> nombre de points a supprimer
  int currentScreen;
  int largeur;
  int hauteur;
  Points points[NB_MAX_POINTS];
  Lines lines[NB_MAX_LINES];
  VirtualScreen virtualsScreen[NB_MAX_VIRTUAL_SCREEN];
  boolean existVirtualScreen[NB_MAX_VIRTUAL_SCREEN];


};
#endif
