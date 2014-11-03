#include "frame.h"
#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
Frame f;
int playerPoint;
void setup()
{
  Serial.begin(9600);
  EsploraTFT.begin();
  EsploraTFT.background(0,0,0);
  f.addVirtualScreen(EsploraTFT.width(),EsploraTFT.height(),0,0);
  f.drawPoint(10,10);
  playerPoint=f.drawPoint(EsploraTFT.width()/2,EsploraTFT.height()/2,0,255,0);
  f.drawRectangle(50,50,10,10);
  //f.drawPoint(25,15);
}

int vectorX=0;
int vectorY=0;
void loop()
{
  vectorX=0;
  vectorY=0;
  if(Esplora.readButton(SWITCH_DOWN)==LOW){
    f.drawPoint(f.getPointPositionX(playerPoint),f.getPointPositionY(playerPoint));
  }
  if(Esplora.readJoystickY() < -256){
    vectorY+=1;
  }
  else if(Esplora.readJoystickY() > 256){
    vectorY-=1;
  }
  if(Esplora.readJoystickX() < -256){
    vectorX-=1;
  }
  else if(Esplora.readJoystickX() > 256){
    vectorX+=1;
  }
  if(vectorX!=0||vectorY!=0){
    f.moveScreen(f.getNbOfCurrentVirtualScreen(),vectorX,vectorY,false);
    f.movePoint(playerPoint,vectorX,vectorY);
    

  }
  else
    f.drawCurrentScreen();
  

  delay(5);
}
