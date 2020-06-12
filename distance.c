#include "depen.h"



double DistanceAB (double latitudeA, double latitudeB, double longitudeA, double longitudeB){ //calculates the distance between two points on the globe

    const double M_PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
    double latA = (latitudeA * (M_PI/180)), latB = (latitudeB * (M_PI/180)), lonA = (longitudeA * (M_PI/180)), lonB = (longitudeB * (M_PI/180));
    double distance = 0;
    const double R = 6372.795477598;

    distance = R * acos(sin(latA)*sin(latB) + cos(latA) * cos(latB) * cos(lonA-lonB));
    return distance;
}
