#ifndef DEFINES_H
#define DEFINES_H

#define PIXELS_X 11
#define PIXELS_Y 11
#define INPUT_NEURONS PIXELS_X * PIXELS_Y
#define HIDDEN_NEURONS 50
#define OUTPUT_NEURONS 6 //количество букв
#define LEARN_EX_NUM 3   //количество примеров на букву

#define RAND_WEIGHT (((float)rand() / (float)RAND_MAX) - 0.5)
#define getSRand() ((float)rand() / (float)RAND_MAX)
#define getRand(x) (int)((x) * getSRand())
#define sqr(x) ((x) * (x))

#endif // DEFINES_H
