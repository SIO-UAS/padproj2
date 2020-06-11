#include "depen.h"
#include "csv.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distance.h"
#include "route.h"

void test_route(void){
  FILE *csvSt, *csvRo, csvback;

  csvSt = fopen("worldcities.csv","r");

  if( csvSt == NULL){
      printf("Fehler beim �ffnen der Datei");
  }

  printf("Geoefnet\n");
  desti* Staedte = NULL;
  int data_c = 0;
  printf("Daten Einlesen Starten\n");
  Staedte = rcs(csvSt, Staedte, &data_c);
  printf("Daten Eingelesen %d Datensaetze gefunden Speicheradr: %p\n", data_c, Staedte);

  fclose(csvSt);







     desti* testc = calloc(4, sizeof(desti));
     if(testc != NULL){
       //printf("ptr testc : %p \n", testc);
     }
     else{
       printf("Konnte keinen Speicher allozieren\n");
     }
       int x =0;
       x=searchid(Staedte, 1040261752, data_c);
       testc[0] = Staedte[x];
       x = searchid(Staedte, 1040038924, data_c);
       testc[1] = Staedte[x];
       x = searchid(Staedte, 1040751740, data_c);
       testc[2] = Staedte[x];
       x = searchid(Staedte, 1040184559, data_c);
       testc[3] = Staedte[x];
       if(x!=0){
       printf("Routen Planer Start");
        }
       if(x!=0){
         x = routen_planer(testc, 4);
       }
  desti* abc = calloc(12, sizeof(desti));

    return;
}















