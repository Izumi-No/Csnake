#include "fruit.h"
#include <stdlib.h>
#include "snake.h"

struct Snake *snakeInit(int x, int y, int length)
{
    struct Snake *snake = malloc(sizeof(struct Snake));
    snake->x = x;
    snake->y = y;
    snake->length = length;
    snake->tail = malloc(sizeof(struct Tail) * length);
    snake->dir = RIGHT;
    return snake;
};

int isSnakeColidedWithTail(struct Snake *snake)
{

    for (int i = 1; i < snake->length; i++)
    {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
        {
            return 1;
        }
    }

    return 0;
}

int isSnakeColidedWithWall(struct Snake *snake, int width, int height, int pxsize)
{
    if (snake->x <= 0 || snake->x >= width - pxsize || snake->y <= 0 || snake->y >= height - pxsize)
    {
        return 1;
    }

    return 0;
}

int isSnakeColidedWithFood(struct Snake *snake, struct Fruit *fruit)
{
    if (snake->x == fruit->x && snake->y == fruit->y)
    {
        // Set the position of the new tail element
        int newTailX = snake->tail[snake->length - 1].x;
        int newTailY = snake->tail[snake->length - 1].y;

        // Increase the snake's length
        snake->length++;

        // Reallocate memory for the tail
        struct Tail *newTail = realloc(snake->tail, sizeof(struct Tail) * snake->length);
        if (newTail == NULL)
        {
            // Handle memory allocation failure
            // Return an error code or exit the program
            return 0;
        }

        // Update the snake's tail with the new memory allocation
        snake->tail = newTail;

        // Shift the tail elements forward
        for (int i = snake->length - 1; i > 0; i--)
        {
            snake->tail[i].x = snake->tail[i - 1].x;
            snake->tail[i].y = snake->tail[i - 1].y;
        }

        // Set the new tail element to the position of the eaten fruit
        snake->tail[0].x = newTailX;
        snake->tail[0].y = newTailY;

        return 1;
    }

    return 0;
}

void addTail(struct Snake *snake)
{
    snake->length++;

    struct Tail *newTail = realloc(snake->tail, sizeof(struct Tail) * snake->length);
    if (newTail == NULL)
    {
        return;
    }

    snake->tail = newTail;

    for (int i = snake->length - 1; i > 0; i--)
    {
        snake->tail[i] = snake->tail[i - 1];
    }

    snake->tail[0].x = snake->x;
    snake->tail[0].y = snake->y;
}

void moveSnake(struct Snake *snake, int speed, int pxsize)
{
    // Store the previous position of the head
    int prevX = snake->x;
    int prevY = snake->y;

    // Update the head position based on direction
    switch (snake->dir)
    {
    case UP:
        snake->y -= speed * pxsize;
        break;
    case DOWN:
        snake->y += speed * pxsize;
        break;
    case LEFT:
        snake->x -= speed * pxsize;
        break;
    case RIGHT:
        snake->x += speed * pxsize;
        break;
    }

    // Update the tail segments
    if (snake->length > 1)
    {
        // Move the last segment to the previous head position
        snake->tail[snake->length - 1].x = prevX;
        snake->tail[snake->length - 1].y = prevY;

        // Shift the remaining tail segments
        for (int i = snake->length - 2; i >= 1; i--)
        {
            snake->tail[i] = snake->tail[i - 1];
        }

        // Update the first segment to the current head position
        snake->tail[0].x = snake->x;
        snake->tail[0].y = snake->y;
    }
}

void snakeFree(struct Snake *snake)
{
    free(snake->tail);
    free(snake);
};
