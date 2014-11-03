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
  playerPoint=f.drawPoint(EsploraTFT.width()/2,EsploraTFT.height()/2,true,0,255,0);
  f.drawRectangle(50,50,10,10,true);
  //f.drawPoint(25,15);
}

int vectorX=0;
int vectorY=0;
int vectorXPlayer=0;
int vectorYPlayer=0;
void loop()
{
 
  vectorX=0;
  vectorY=0;
  vectorYPlayer=0;
  vectorXPlayer=0;
  if(Esplora.readButton(SWITCH_DOWN)==LOW){
    //f.drawPoint(f.getPointPositionX(playerPoint),f.getPointPositionY(playerPoint));
    vectorYPlayer+=1;
  
  }
  if(Esplora.readButton(SWITCH_UP)==LOW){
    vectorYPlayer-=1;
  }
  if(Esplora.readButton(SWITCH_LEFT)==LOW)
    {
      vectorXPlayer-=1;
    }
  if(Esplora.readButton(SWITCH_RIGHT)==LOW)
    {
      vectorXPlayer+=1;
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
    f.moveScreen(f.getNbOfCurrentVirtualScreen(),vectorX,vectorY);
  }
  if(vectorXPlayer!=0||vectorYPlayer!=0){
    f.movePoint(playerPoint,vectorXPlayer,vectorYPlayer);
  }

  
  else
    f.drawCurrentScreen();
  
  

  delay(10);
}
