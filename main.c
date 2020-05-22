#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *city_n;
  char *country;
  char *iso;
  double lat;
  double lng;
  int id;
  short int cap;
  int pop;
}desti;

int main()
{
    FILE *csvSt, *csvRo;

    csvSt = fopen("worldcities.csv","r");

    if( csvSt == NULL){
        printf("Fehler beim Öffnen der Datei");
    }
    desti Staedte[1];

    char buf[1024];
    int row_count = 0;
    int field_count = 0;
    while (fgets(buf, 1024, csvSt)) {

        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }
        realloc(Staedte,sizeof(desti)*(row_count-1));

        char *field = strtok(buf, ",");
        while (field) {

            if (field_count == 1) {
                Staedte[row_count -2].city_n = field;
            }
            if (field_count == 2) {
                Staedte[row_count -2].lat = atof(field);
            }
            if (field_count == 3) {
                Staedte[row_count -2].lng = atof(field);
            }
            if (field_count == 4) {
                Staedte[row_count -2].country = field;
            }
            if (field_count == 6) {
                Staedte[row_count -2].iso = field;
            }
            if (field_count == 8 && field == 'primary') {
                Staedte[row_count -2].cap = 1;
            }
            if (field_count == 9) {
                Staedte[row_count -2].pop = atoi(field);
            }
            if (field_count == 10) {
                Staedte[row_count -2].id = atoi(field);
            }
                field = strtok(NULL, ",");
                field_count++;
            }

        }

    fclose(csvSt);
    int x = 0;
    while(x <= row_count){
        printf("%s %s %s %f %f %d %d/n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
        x++;
    }





    return 0;
}
