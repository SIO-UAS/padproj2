#include "depen.h"
#include "csv.h"
#include "search.h"




int main(){
  FILE *csvSt, *csvRo, *csvback;

  csvSt = fopen("worldcities.csv","r");

  if( csvSt == NULL){
      printf("Fehler beim �ffnen der Datei");
  }

  printf("Geoefnet\n");
  desti* Staedte = NULL;
  int data_c = 0;
  printf("Daten Einlesen Starten\n");
  printf("Daten Eingelesen %d Datensaetze gefunden Speicheradr: %p\n", data_c, Staedte);
  Staedte = rcs(csvSt, Staedte, &data_c);
  fclose(csvSt);
  printf("Daten Eingelesen %d Datensaetze gefunden Speicheradr: %p\n", data_c, Staedte);


  int x = 0;
  while(x <= data_c){
      printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
      x++;
  }
  printf("\nSearching ID ...");
  x = searchid(Staedte, 1124019423, data_c);
  printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );



}
