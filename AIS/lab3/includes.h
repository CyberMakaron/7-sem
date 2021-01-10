#ifndef INCLUDES_H
#define INCLUDES_H

#define MAX_CITIES 30
#define MAX_DISTANCE 100
#define MAX_TOUR (MAX_CITIES * MAX_DISTANCE)
#define MAX_ANTS 30

#define MAX_TOURS 20
#define MAX_TIME (MAX_TOURS * MAX_CITIES)
#define INIT_PHEROMONE (1.0 / MAX_CITIES)

#include <QVector>
#include <QtMath>
#include <ctime>
#include <QDebug>

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

class Ant{
public:
    int curCity;
    int nextCity;
    QVector<unsigned char> tabu;
    int pathIndex;
    QVector<unsigned char> path;
    double tourLength;
    Ant(): tabu(MAX_CITIES), path(MAX_CITIES){}
};



#endif // INCLUDES_H
