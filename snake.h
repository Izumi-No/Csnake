
#include "fruit.h"

#ifndef SNAKE_H
#define SNAKE_H

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Tail
{
    int x, y;
};

struct Snake
{
    int x, y;
    struct Tail *tail;
    int length;
    int dir;
};

#endif

struct Snake *snakeInit(int x, int y, int length);

int isSnakeColidedWithTail(struct Snake *snake);

int isSnakeColidedWithWall(struct Snake *snake, int width, int height, int pxsize);

int isSnakeColidedWithFood(struct Snake *snake, struct Fruit *fruit);

void addTail(struct Snake *snake);

void moveSnake(struct Snake *snake, int speed, int pxsize);
