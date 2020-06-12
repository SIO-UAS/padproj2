#include "depen.h"
#include "csv.h"

int searchid(desti *Staedte, int id, int max){ // Wurst Käs Zenario jet
  int x = 0;

  while(x < max && Staedte[x].id != id){
    x++;
  }
  return x;
}


desti* searchISO(desti *Staedte, char* iso, int max, int *rc){
    desti* result = NULL;
    desti* test = NULL;
    *rc = 1;
    int x = 0;

    while(x < max){
      if (Staedte[x].iso != NULL) {

      if(Staedte[x].iso[0] == iso[0]){

        if(Staedte[x].iso[1] == iso[1]){

          if(Staedte[x].iso[2] == iso[2]){


            test = (desti*) realloc(result,(sizeof(desti))*(*rc));
            if(test == NULL){
              printf("Some Error Accured");
              return result;
            }
            result = test;
            result[*rc-1] = (Staedte[x]);
            //printf("passed\n");
            (*rc)++;
          }
          else{}
        }
        else{}
      }
      else{}


      }
      else{}
      x++;

    }
    //printf("Suche abgeschlossen\n");

    return result;
}

desti* searchName(desti *Staedte, char* name, int max, int *rc){
    desti* result = NULL;
    *rc = 0;
    int x = 0;
    int strlena = 0;
    int strlenb = 0;
    strlenb = myStrLen(name);

    while(x < max){
      if (Staedte[x].city_n != NULL) {

        if(Staedte[x].city_n[0] == name[0]){

        if(strcmp(Staedte[x].city_n, name) == 0){

          result = (desti*) realloc(result,(sizeof(desti))*(*rc+1));
          result[*rc] = (Staedte[x]);
          (*rc)++;

        }
        else{}
      }
      else{}


      }
      else{}
      x++;

    }

    return result;
}
