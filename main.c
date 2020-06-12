#include "depen.h"
#include "csv.h"
#include "search.h"
#include "sort.h"
#include "del.h"
#include "disp.h"
#include "distance.h"
#include "route.h"

desti* search_m(desti* m, desti* res, int *count, int max){
  int ui =0;
  int x;
  char buff[256];

  //desti* res;
  desti* test;
  desti* tmp;
  printf("Nach welchem Kriterium möchten Sie suchen?\n0...Id  1...ISO  2...Stadt? :");
  scanf(" %d", &ui);
  switch(ui){
    case 0:
    printf("Geben Sie eine ID ein :" );
    scanf(" %d", &ui);
    x = searchid(m, ui, max);
    disp_dlistad(&m[x], 1);
    printf("Wollen Sie einen Openstreetmap-Link? 0(Nein) / 1(Ja)  : ");
    scanf(" %d", &ui);
    if(ui == 1){
      printMap_Link(m[x].lat, m[x].lng);
    }
    printf("Ist das die Stadt nach der Sie suchen. Wollen Sie sie zur Route hinzufügen? 1/0 : ");
    scanf(" %d", &ui);
    if(ui == 1){
      test = realloc(res, sizeof(desti)*(*count+1));
      if(test == NULL){
        return NULL;
      }
      res = test;
      res[*count] = m[x];
      (*count)++;
    }
    break;
    case 1:
    printf("Geben Sie den 3 Stelligen ISO code ein von dem Land nach dem Sie suchen wollen : ");
    scanf(" %s", buff);
    tmp = searchISO(m,buff,max,&x);
    disp_dlistad(tmp, x);
    printf("Merken Sie sich die ID\n");
    break;
    case 2:
    printf("Geben Sie den Staedtenamen ein nach dem Sie suchen wollen : ");
    scanf(" %s", buff);
    tmp = searchName(m,buff,max,&x);
    disp_dlistad(tmp, x-1);
    printf("Merken Sie sich die ID\n");
    break;

  }
  return res;
}

int main(){
  int ui_i =0;
  int su = 0;
  int x =0;
  FILE *csvSt;
  desti* ma = NULL;
  desti* work = NULL;
  desti* test =NULL;
  int data_c;
  int res =0;
  char path[512];
  printf("##########RouteFinder v1##########\n");
  printf("Wollen Sie eine eigene Datei einlesen(1) oder die Mitgelieferte Datei verwenden(0)? :");
  while(su != 1){
    scanf(" %d", &ui_i);
    if(ui_i == 1){
      printf("Geben Sie den Pfad zur CSV datei ein: ");
      scanf(" %s", path);
      csvSt = fopen(path, "r");
    }
    else{
        csvSt = fopen("../worldcities.csv","r");

    }
    if(csvSt == NULL){
      su = 0;
      printf("\nFehler beim Öffnen der Datei : Eigene Datei einlesen (1) oder Mitgelieferte verwenden(0)? :");
    }
    else{

      su =1;
    }

}
printf("Datei Erfolgreich geöffnet, einlesen wird gestartet...\n");
printf("Ziele für die Routen findung können Sie nur in Menü Punkt Staedte suchen unter ID suchen\n");
ma = rcs(csvSt, ma, &data_c);
printf("Datei eingelesen, %d Datensaetze gefunden\n\n", data_c);
ui_i = 1;
while(ui_i != 0){
  printf("Was wollen Sie machen?\n0...Programm beenden 1...Steadte suchen\n 2...Daten sortieren 3...Route planen(Bitte vorher Steadte suchen)\n Ihre Auswahl : ");
  scanf(" %d", &ui_i);
  switch(ui_i){
    case 0:
    break;
    case 1:
      test = search_m(ma, work, &res, data_c);
      if(test == NULL){
        //printf("Ein Unerwarteter Fehler ist aufgetreten! Versuchen Sie es nochmal, sollte der Fehler bestehen bleiben starten Sie das Programm neu\n");
        continue;
      }
      work = test;
    break;
    case 2:
    printf("Wie wollen Sie sortieren? Nach Population(0), ID(1), Alpabetisch[Stadt(2), ISO(3), Land(4)] : ");
    scanf(" %d", &ui_i);
    switch(ui_i){
      case 0:
      ma = inSort_id(ma, data_c);
      break;
      case 1:
      ma = inSort_id(ma, data_c);
      break;
      case 2:
      ma = bucket_sb(ma, data_c, 0);
      break;
      case 3:
      ma = bucket_sb(ma, data_c, 1);
      break;
      case 4:
      ma = bucket_sb(ma, data_c, 2);
      break;
      default:
      printf("Ungültige Eingabe\n");
      break;
    }
    ui_i = 1;

    break;
    case 3:
    if(work != NULL && res >2){
      x = routen_planer(work, res);
    }
    else{
      printf("Zu wenige Ziele\n");
    }
    break;
  }
  printf("Diese Ziele(%d) sind derzeit gesetzt :\n", res);
  disp_dlistad(work, res);

}
printf("Auf wiedersehen!\n");
desti* abc = calloc(12, sizeof(desti));
delete_all(ma, data_c);
free(work);
}
