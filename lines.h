#ifndef LINES_H
#define LINES_H
#include <Esplora.h>

class Lines{
 public :
  Lines(int x1=0,int y1=0,int x2=0,int y2=0,boolean secure=false,boolean exist=false,int r=255,int g=255,int b=255);

  int x1;
  int y1;
  int x2;
  int y2;
  int r;
  int g;
  int b;
  boolean secure;
  boolean exist;
};
#endif
