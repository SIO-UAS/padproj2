#include "depen.h"
#include "csv.h"
#include "search.h"
#include "sort.h"
#include "del.h"
#include "disp.h"




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
  /*while(x <= data_c){
      printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
      x++;
  }*/
  disp_dlistad(Staedte, data_c);

  printf("\nSearching ID ...");
  x = searchid(Staedte, 1124019423, data_c);
  printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );

  int res = 0;

  printf("Searching for ISO AUT... \n");
  desti* sres = searchISO(Staedte, "AUT", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
  //delete_all(sres, res);

  disp_dlistad(sres, res);

  /*while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }*/
  //free(sres);
sres =NULL;
printf("\n\n");
/*  desti* testc = calloc(4, sizeof(desti));
  testc[0] = Staedte[searchid(Staedte, 1040261752, data_c)];
  testc[1] = Staedte[searchid(Staedte, 1040038924, data_c)];
  testc[2] = Staedte[searchid(Staedte, 1040751740, data_c)];
  testc[3] = Staedte[searchid(Staedte, 1040184559, data_c)];
  printMap_Link(testc[0].lat, testc[0].lng);
  printMap_Link(testc[1].lat, testc[1].lng);
  printMap_Link(testc[2].lat, testc[2].lng);
  printMap_Link(testc[3].lat, testc[3].lng);
  disp_dlistad(testc, 3);*/

  res = 0;
  printf("Searching for City(s) named Vienna... \n");
  sres = searchName(Staedte, "Vienna", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
  disp_dlistad(sres, res-1);
  //free(sres);
/*
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }
*/
  res = 0;
  printf("Searching for City(s) named Paris... \n");
  sres = searchName(Staedte, "Paris", data_c, &res);
  if(sres == NULL){
    printf("Fehler bei der Suche!\n");
    return 0;
  }
  printf("Gefunden : %d Ergebnisse\n", res);
  x=0;
  disp_dlistad(sres, res);
  //free(sres); Linux Laufzeitfehler
  //delete_all(sres, res);
  sres = NULL;
/*
  while(x < res){
    printf("%s %s %s %f %f %d %d\n",sres[x].city_n,sres[x].country,sres[x].iso,sres[x].lat,sres[x].lng,sres[x].pop,sres[x].id );
    x++;
  }
*/
  printf("Sortieren Nach ID:\n");
  desti* sorted = NULL;
  sorted = inSort_id(Staedte, (data_c-2));
  /*while(x <= (data_c-2)){
      printf("%s %s %s %f %f %d %d\n",sorted[x].city_n,sorted[x].country,sorted[x].iso,sorted[x].lat,sorted[x].lng,sorted[x].pop,sorted[x].id );
      x++;
  }*/
  printf("\033[32m"); // Green
  disp_dlistad(sorted, data_c);
  printf("\033[0m");
  //free(sorted);
  printf("Sortieren Nach Population:\n");

  sorted = inSort_pop(Staedte, (data_c-2), 1);
  printf("\033[34m"); //Blue
  disp_dlistad(sorted, data_c);
  printf("\033[0m");
  printf("Test");
  //free(sorted);

  printf("Sortieren Nach ersten char eines Staedtenamens:\n");
    /*while(x <= (data_c-2)){
        printf("%-30s %-25s %-9d\n",sorted[x].city_n,sorted[x].country,sorted[x].pop);
        x++;
    }*/
    x=0;
    //disp_dlistad(Staedte, data_c);
    sorted = bucket_sb(Staedte, (data_c-2), 0);
    printf("\033[35m"); //Magenta
    disp_dlistad(sorted, (data_c-2));
    printf("\033[0m");
  /*  while(sorted[x].city_n != NULL){

        printf("%-30s %-25s %-9d\n",sorted[x].city_n,sorted[x].country,sorted[x].id);
        x++;


    }*/

    printf("\n\n");
    desti* q = calloc(15, sizeof(desti)); // Damit das Programm bei MacOS nicht während der kritischen laufzeit einen malloc Fehler hat
    //delete_all(sorted, (data_c-2));
    printf("gebe Speicher wieder frei:");
    delete_all(Staedte, (data_c-2));
}
