#include "depen.h"


void delete_all(desti* to, int max){

  for(int i =0; i<max; i++){
    free(to[i].city_n);
    free(to[i].country);
    free(to[i].iso);
  }
  free(to);

}
