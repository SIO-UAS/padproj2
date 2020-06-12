#include "depen.h"
#include "csv.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distance.h"
#include "route.h"

void test_distance(void){
printf ("%f km\n",DistanceAB(35.6850,19.0170,139.7514,72.8570));//tokyo + mumbai
printf ("6740.39 km\n");
printf ("%f km\n",DistanceAB(40.6943,19.4424,-73.9249,-99.1310));//new yprk + mexico city
printf("3359.38 km\n");
printf ("%f km\n",DistanceAB(-12.0480,19.0170,-77.0501,72.8570)); //lima peru + mumbai
printf("16694 km\n");


}
