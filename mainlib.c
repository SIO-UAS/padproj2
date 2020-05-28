#include "csv.h"

int main(){
  FILE *csvSt, *csvRo;

  csvSt = fopen("worldcities.csv","r");

  if( csvSt == NULL){
      printf("Fehler beim �ffnen der Datei");
  }
  desti* Staedte = NULL;
  int data_c = 0;
  //data_c = rcs(csvSt, Staedte);

  fclose(csvSt);
  int x = 0;
  while(x <= data_c){
      printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
      x++;
  }


}
