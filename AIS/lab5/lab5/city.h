#ifndef CITY_H
#define CITY_H

#include <ctime>
#include <QtMath>
#include "includes.h"

class City {
public:
    int x;
    int y;
    City(){
        x = rand() % MAX_CITIES;
        y = rand() % MAX_CITIES;
    }
    friend bool operator==(const City& left, const City& right);
    double calcDistance(City c){
        int xd = abs(x - c.x);
        int yd = abs(y - c.y);
        return qSqrt(xd * xd + yd * yd);
    }
};

#endif // CITY_H
