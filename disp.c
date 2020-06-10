#include "depen.h"
void disp_dlistad(desti* to, int count){ //display desti list all data
  int x = 0;
  while(x <= count){
      if(to[x].city_n!= NULL){
        printf("%s %s %s %f %f %d %d\n",to[x].city_n,to[x].country,to[x].iso,to[x].lat,to[x].lng,to[x].pop,to[x].id );
        x++;
      }
      else{
        return;
      }
  }

}

void printMap_Link(float lat, float log){ //Print Openstreetmap Link to Cordinates

  printf("https://www.openstreetmap.org/search?query=%f%%2C%f", lat, log);

  return;
}
