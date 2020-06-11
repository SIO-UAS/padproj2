#include "depen.h"
#include <math.h>
#define const double R = 6372.795477598;

double DistanceAB (double latitudeA, double latitudeB, double longitudeA, double longitudeB){
    double latA = (latitudeA * (M_PI/180)), latB = (latitudeB * (M_PI/180)), lonA = (longitudeA * (M_PI/180)), lonB = (longitudeB * (M_PI/180));
    double distance = 0;
    distance = R * acos(sin(latA)*sin(latB) + cos(latA) * cos(latB) * cos(lonA-lonB));
    return distance;
}
