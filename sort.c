#include "depen.h"

desti* inSort_id(desti *Staedte, int max){
  desti help;
  int id_tps;
  int b;
  for(int i = 1; i < max; i++){
    id_tps = Staedte[i].id;
    help = Staedte[i];
    b=i;
    while((b>0)&&(Staedte[b-1].id > id_tps)){
      Staedte[b] = Staedte[b-1];
      b = b-1;
    }
    Staedte[b] = help;

  }
  return Staedte;
}
