
#ifndef FRUIT_H
#define FRUIT_H

struct Fruit
{
    int x;
    int y;
    int color;
};

#endif // FRUIT_H

struct Fruit *fruitInit(int x, int y, int color);
void fruitFree(struct Fruit *fruit);
