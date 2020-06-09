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

desti* bucket_sb(desti* Staedte, int max, int sortkret){ //Emergency Bucket_sortbaka (in order to avoid two times the same letter) This is stupid i know, but memory friendly
  desti* result = NULL;
  desti* test = NULL;
  int x =0;
  char det;
  for(int a =0; a<26; a++){
    printf("\nDurchlauf Nr. %d", a);
    for(int i = 0; i<max; i++){
      switch(sortkret){
        case 0:   //Nach Staedtenamen
        if(Staedte[i].city_n != NULL){
          det = Staedte[i].city_n[0];
          if(det >= 'a'){
            det-='a';
            det+='A';
          }
          else{

          }
        }
        else{}
        break;
        case 1:
        if(Staedte[i].iso != NULL){
          det = Staedte[i].iso[0];
          if(det >= 'a'){
            det-='a';
            det+='A';
          }
          else{

          }
        }
        else{}
        break;
        case 2:
        if(Staedte[i].country != NULL){
          det = Staedte[i].country[0];
          if(det >= 'a'){
            det-='a';
            det+='A';
          }
          else{

          }
        }
        else{}
        break;
        default:
        break;
      }
      if((i % 1000) ==1){
        printf("|");
      }
      //printf("x: %d ... a : %c ... det : %c", x,((char)a)+'A', det);
      if(det == ((char)a)+'A'){
        test = realloc(result, sizeof(desti)*(x+1));
        if(test != NULL){
          result = test;
        }
        else{
          return result;
        }
        result[x]=(Staedte[i]);
        printf("R: %s <- %s : S\n", result[x].city_n, Staedte[i].city_n);
        x++;
      }

    }

  }

  return result;
}
