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

desti* aBucketSort(desti *Steadte, int max){
  desti* result = NULL;
  desti* test = NULL;
  desti** buckets = (desti**)malloc(26*sizeof(desti*));
  int into;
  int n[26];
  for(int i = 0; i < 26; i++){
    n[i] = 0;
  }

    for(int i = 0; i<max; i++){

      if(Steadte[i].city_n != NULL){
        if(Steadte[i].city_n[0] > 96){
          into = (int)(Steadte[i].city_n[0] - 'a');
        }
        else{
          into = (int)(Steadte[i].city_n[0] - 'A');
        }
        n[into]++;
        test = realloc(buckets[into], sizeof(desti)*n[into]);
        if(test != NULL){
          buckets[into] = test;
          buckets[into][n[into]] = Steadte[i];
        }

      }

    }

    result = (desti*)malloc(sizeof(desti*) * max);
    int z = 0;
    for(int i=0; i < 26; i++){
      for(int b=0; b< n[i]; b++){
        if(z < max){
          result[z]=buckets[i][b];
          z++;
        }
        else{
          printf("I have a Question: HOW?");
        }
      }
    }
    return result;
}
