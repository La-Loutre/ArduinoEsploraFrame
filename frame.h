#ifndef FRAME_H
#define FRAME_H
#include "points.h"
#include "virtualScreen.h"
#include <Esplora.h>

#define NB_MAX_POINTS 10
#define NB_MAX_VIRTUAL_SCREEN 4

class Frame{
public :
  Frame(int=500,int=500);// x,y
  void addVirtualScreen(int,int,int,int);//TFT largeur ,TFT hauteur , posX , pos Y
  void drawCurrentScreen();
  void setVirtualScreen(int );//numero
  int getNbOfVirtualScreen();
  int getNbOfCurrentVirtualScreen();
  void moveScreen(int,int,int);//numeroScreen , addx,addy
  void drawPoint(int ,int);//x ,y (frame based)
  boolean pointsIsInVirtualScreen(Points ,VirtualScreen );
private:
  void clearScreen(int);//numeroScreen
  int currentScreen;
  int largeur;
  int hauteur;
  Points points[NB_MAX_POINTS];
  boolean existPoint[NB_MAX_POINTS];
  VirtualScreen virtualsScreen[NB_MAX_VIRTUAL_SCREEN];
  boolean existVirtualScreen[NB_MAX_VIRTUAL_SCREEN];


};
#endif
