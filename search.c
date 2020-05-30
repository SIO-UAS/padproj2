#include "depen.h"

int searchid(desti *Staedte, int id, int max){ // Wurst Käs Zenario jet
  int x = 0;
  while(x < max && Staedte[x].id != id){
    x++;
  }
  return x;
}


desti* searchISO(desti *Staedte, char* iso, int max, int *rc){
    desti* result = NULL;
    rc = 0;
    int x = 0;
    while(x < max){
      if(Staedte->iso[0] == iso[0]){
        if(Staedte->iso[1] == iso[1]){
          if(Staedte->iso[2] == iso[2]){
            rc++;
            result = (desti*) realloc(result, (*rc)*(sizeof(desti)));
          }
          else{}
        }
        else{}
      }
      else{}

    }
    return result;
}
