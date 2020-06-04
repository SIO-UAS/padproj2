#include "depen.h"

desti* inSort_id(desti *Staedte, int max){ //insertion sort
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

desti* inSort_pop(desti *Staedte, int max, int dir){ //insertion sort
  desti help;
  int id_tps;
  int b;
  for(int i = 1; i <= max; i++){
    id_tps = Staedte[i].pop;
    help = Staedte[i];
    b=i;
    while((b>0)&&(Staedte[b-1].pop > id_tps)){
      Staedte[b] = Staedte[b-1];
      b = b-1;
    }
    Staedte[b] = help;

  }
  if(dir == 1){
    for(int u = 0; u <= (max/2); u++){
      help = Staedte[u];
      Staedte[u] = Staedte[max-u];
      Staedte[max-u] = help;
    }


  }
  return Staedte;
}
