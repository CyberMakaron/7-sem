#include "includes.h"

double getSRand(){
    return (double)rand() / (double)RAND_MAX;
}

double getRand(int x){
    return x * getSRand();
}
