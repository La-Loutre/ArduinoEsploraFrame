#include "frame.h"
#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
Frame f;
void setup()
{
  Serial.begin(9600);
  EsploraTFT.begin();
  EsploraTFT.background(0,0,0);
  f.addVirtualScreen(EsploraTFT.width(),EsploraTFT.height(),0,0);
  f.drawPoint(10,10);
  f.drawPoint(15,15);
  //f.drawPoint(25,15);
}
int vectorX=0;
int vectorY=0;
void loop()
{
  vectorX=0;
  vectorY=0;
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
  if(vectorX!=0||vectorY!=0)
    f.moveScreen(f.getNbOfCurrentVirtualScreen(),vectorX,vectorY);
  else
    f.drawCurrentScreen();
  

  delay(10);
}
