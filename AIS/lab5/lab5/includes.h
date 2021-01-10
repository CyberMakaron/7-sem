#ifndef INCLUDES_H
#define INCLUDES_H

#define MAX_CHROMS 10       // Группы хромосом
#define MAX_CITIES 20
#define MAX_DISTANCE 100
#define MAX_GENERATIONS 200
#define SPLIT_COUNT 1

#include <QTime>
#include <QDebug>

//#define getSRand() ((double)rand() / (double)RAND_MAX)
//#define getRand(x) (double)((x) * getSRand())

typedef struct population {
    double fitness;          // здоровье
    int cities[MAX_CITIES]; // города
} PopulationType;          // хромосома (особь)

double getSRand();
double getRand(int x);

#endif // INCLUDES_H
