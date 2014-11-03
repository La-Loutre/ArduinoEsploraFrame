#ifndef FRAME_H
#define FRAME_H
#include "points.h"
#include "virtualScreen.h"
#include <Esplora.h>

#define NB_MAX_POINTS 100
#define NB_MAX_VIRTUAL_SCREEN 4
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
  void moveScreen(int,int,int);//numeroScreen , addx,addy
  void movePoint(int,int,int);//Id point , addx , addy
  int drawPoint(int ,int,int=DEF_R,int=DEF_G,int=DEF_B);//x ,y (frame based),r,g,b, renvoie l'id du point 
  boolean pointsIsInVirtualScreen(Points ,VirtualScreen );

  //Non minimal interface function
  void drawRectangle(int,int,int,int);//x,y,largeur,hauteur
private:
  void clearScreen(int);//numeroScreen
  void clearPoint(int);//id point
  int currentScreen;
  int largeur;
  int hauteur;
  Points points[NB_MAX_POINTS];
  boolean existPoint[NB_MAX_POINTS];
  VirtualScreen virtualsScreen[NB_MAX_VIRTUAL_SCREEN];
  boolean existVirtualScreen[NB_MAX_VIRTUAL_SCREEN];


};
#endif
