#include <stdlib.h>

#include "fruit.h"

struct Fruit *fruitInit(int x, int y, int color)
{
    struct Fruit *fruit = malloc(sizeof(struct Fruit));
    fruit->x = x;
    fruit->y = y;
    fruit->color = color;
    return fruit;
};

void fruitFree(struct Fruit *fruit)
{
    free(fruit);
}
