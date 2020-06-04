#include "depen.h"
#include "csv.h"
#include "search.h"
#include "sort.h"




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
/*  while(x <= data_c){
      printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
      x++;
  }
*/
  printf("\nSearching ID ...");
  x = searchid(Staedte, 1124019423, data_c);
  printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );

  int res = 0;

  printf("Searching for ISO USA... \n");
  desti* sres = searchISO(Staedte, "USA", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
/*
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }
*/
  res = 0;
  printf("Searching for City(s) named Vienna... \n");
  //sres = searchName(Staedte, "Vienna", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
/*
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }
*/
  res = 0;
  printf("Searching for City(s) named Paris... \n");
  sres = searchName(Staedte, "Medellin", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
/*
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }
*/
  printf("Sortieren ....\n");
/*  desti* sorted = NULL;
  sorted = inSort_id(Staedte, (data_c-2));
  while(x <= (data_c-2)){
      printf("%s %s %s %f %f %d %d\n",sorted[x].city_n,sorted[x].country,sorted[x].iso,sorted[x].lat,sorted[x].lng,sorted[x].pop,sorted[x].id );
      x++;
  }
  */
  desti* sorted = NULL;
    sorted = inSort_pop(Staedte, (data_c-2), 1);
    while(x <= (data_c-2)){
        printf("%-30s %-25s %-9d\n",sorted[x].city_n,sorted[x].country,sorted[x].pop);
        x++;
    }

}
