#include <math.h>

double CalcDistance(double longtitude1, double latitude1, double longtitude2, double latitude2 ){
    return sqrt(pow((latitude1 - latitude2),2) + pow((longtitude1 - longtitude2),2));
}
