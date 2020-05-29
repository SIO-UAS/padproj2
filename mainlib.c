#include "depen.h"
#include "csv.h"

int searchid(desti *Staedte, int id){ // Wurst Käs Zenario jet
  int x = 0;
  while(Staedte[x].id != 0 && Staedte[x].id != id){
    x++;
  }
  return x;
}


int main(){
  FILE *csvSt, *csvRo;

  csvSt = fopen("worldcities.csv","r");

  if( csvSt == NULL){
      printf("Fehler beim �ffnen der Datei");
  }
  desti* Staedte = NULL;
  int data_c = 0;
  data_c = rcs(csvSt, Staedte);

  fclose(csvSt);
  int x = 0;
  while(x <= data_c){
      printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
      x++;
  }
  printf("\nSearching ID ...");
  x = searchid(Staedte, 1124019423);
  printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );



}
