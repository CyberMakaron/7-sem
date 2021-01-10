#ifndef LOADNETWORK_H
#define LOADNETWORK_H

#include "semanticnetwork.h"

class LoadNetwork{
public:
    LoadNetwork();
    static void loadTask1(SemanticNetwork &net);
    static void loadTask2(SemanticNetwork &net);
    static void loadTask3(SemanticNetwork &net);
};

#endif // LOADNETWORK_H
