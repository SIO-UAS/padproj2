#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/*typedef struct {
  char *city_n;
  char *country;
  char *iso;
  double lat;
  double lng;
  int id;
  short int cap;
  int pop;
}desti;
*/
char* myStrDub(char* s){
    char* ret = NULL;
    int til = 0;
    while(s[til] != '\0'){ //Mit sizeof(*s)/sizeof(char) hat nicht funktioniert und nur 1 ausgegeben :( (&s, s) haben immer acht ausgegeben
        til++;
    }
    ret = calloc(til+1, sizeof(char));
    if(ret == NULL){
        printf("Something went horible wrong");
        return NULL;
    }
    for(int i = 0; i< til; i++){
        ret[i] = s[i];
    }
    return ret;
}

char* myStrRev(char* s){
    char* ret = NULL;
    int til = 0;
    while(s[til] != '\0'){
        til++;
    }
    ret = calloc(til+1, sizeof(char));
    if(ret == NULL){
        printf("Something went horible wrong");
        return NULL;
    }
    for(int i = 0; i< til; i++){
        ret[i] = s[(til-1)-i];
    }
    return ret;
}

int myStrLen(char* s){
    int til = 0;
    while(s[til] != '\0'){
        til++;
    }
    return til;
}

char* myStrCut(char* s, int a, int b){
    char* ret = NULL;
    int max = 0;
    int revc = 0;

     //
    if (a>b){
      revc = 1;
    int temp =0;
    temp =b;
    b = a;
    a = temp;

    }
    else{
      revc = 0;
    }
    a--;
    max = myStrLen(s);

    if(s == NULL){
      return NULL;
    }


    if((a < 0 && b <0) || (a > max && b > max)){
        ret = calloc(1, sizeof(char));
        return ret;
    }
    if((a < 0 && b > max) || (a > max && b < 0)){
      if(revc > 0){
        ret = myStrRev(s);
      }
      else{
        ret = myStrDub(s);
      }
      return ret;
    }
    if(a > max || b > max){
      if(revc > 0 ){
        a = max;
//printf("a = max");
      }
      else{
//printf("B = max");
        b = max;
      }
    }
    if(a < 0 || b < 0){
      if(revc){
    b = 0;
      }
      else{
        a=0;
      }

    }


        ret = calloc((b-a)+1, sizeof(char));
        if(ret == NULL){
            printf("Something went horibly wrong");
            return NULL;
        }
    //printf("Cutting %s von %d bis %d\n",s ,a, b);
        for(int i = 0; i< (b-a); i++){
            ret[i] = s[i+a];
//printf("¬%d, b=%d", (i+a), b);

        }
//printf("%s", ret);
        if(revc > 0){
          return myStrRev(ret);
        }
        else{
          return ret;
      }

    return ret;
}

int main()
{
    FILE *csvSt, *csvRo;

    csvSt = fopen("worldcities.csv","r");

    if( csvSt == NULL){
        printf("Fehler beim �ffnen der Datei");
    }
    desti* Staedte = NULL;
    desti* test = NULL;

    Staedte = (desti*) realloc(Staedte, sizeof(desti));

    char buf[1024];
    long int row_count = 0;
    int field_count = 0;
    int z = 0;
    while (fgets(buf, 1024, csvSt)) {

        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }
        test = (desti*) realloc(Staedte,sizeof(desti)*(row_count-1));
        if(test == NULL){
            break;
        }
        else{
            Staedte = test;
        }
        if((row_count % 100)==1){
            z++;
        }

        char *field = strtok(buf, "\"\",");
        while (field) {
            field = myStrCut(field, 2, myStrLen(field)-1);

            if (field_count == 1) {
                Staedte[row_count -2].city_n = myStrDub(field);
                //printf("%s",Staedte[row_count -2].city_n);
            }
            if (field_count == 2) {
                Staedte[row_count -2].lat = atof(field);
                //printf("%f",Staedte[row_count -2].lat);
            }
            if (field_count == 3) {
                Staedte[row_count -2].lng = atof(field);
            }
            if (field_count == 4) {
                Staedte[row_count -2].country = myStrDub(field);
            }
            if (field_count == 6) {
                Staedte[row_count -2].iso = myStrDub(field);
            }
            if (field_count == 8 && (strcmp(field,"primary") == 0)) {
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
        printf("%s %s %s %f %f %d %d\n",Staedte[x].city_n,Staedte[x].country,Staedte[x].iso,Staedte[x].lat,Staedte[x].lng,Staedte[x].pop,Staedte[x].id );
        x++;
    }





    return 0;
}
