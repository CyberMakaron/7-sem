#include "includes.h"

bool operator==(const City& left, const City& right) {
    return left.x == right.x and left.y == right.y;
}
