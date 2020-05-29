#include "depen.h"

int searchid(desti *Staedte, int id, int max){ // Wurst Käs Zenario jet
  int x = 0;
  while(x < max && Staedte[x].id != id){
    x++;
  }
  return x;
}
