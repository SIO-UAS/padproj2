/*
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

  int res = 0;
  x=0;
  printf("Searching for ISO AUT... \n");
  desti* sres = searchISO(Staedte, "AUT", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }


}
*/
