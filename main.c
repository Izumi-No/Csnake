#include <stdlib.h>
#include "SDL2/SDL.h"

#include "snake.h"
#include "fruit.h"
#include "render.h"
#include "kbdlistener.h"
#include "color.h"

int done = 0;

// Define the game constants
#define WIDTH 500
#define HEIGHT 500
#define FPS 10
#define FRAME_DELAY (1000 / FPS)
#define PIXEL_SIZE 20
#define SPEED 1

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    // Create the game window
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window)
    {
        SDL_Quit();
        return 1;
    }

    // Create the renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize random number generator
    srand(SDL_GetTicks());

    struct Snake *snake = snakeInit((rand() % (WIDTH / PIXEL_SIZE - 2) + 1) * PIXEL_SIZE, (rand() % (HEIGHT / PIXEL_SIZE - 2) + 1) * PIXEL_SIZE, 3);
    struct Fruit *fruit = fruitInit((rand() % (WIDTH / PIXEL_SIZE)) * PIXEL_SIZE, (rand() % (HEIGHT / PIXEL_SIZE)) * PIXEL_SIZE, 0);

    Uint32 frameStart;
    int frameTime;

    while (!done)
    {
        frameStart = SDL_GetTicks();
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                ListenKeyboard(snake, &event);
                break;
            case SDL_QUIT:
                done = 1;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        moveSnake(snake, SPEED, PIXEL_SIZE);

        if (isSnakeColidedWithWall(snake, WIDTH, HEIGHT, PIXEL_SIZE) || isSnakeColidedWithTail(snake))
        {
            done = 1;
        }

        if (isSnakeColidedWithFood(snake, fruit))
        {
            fruit->x = (rand() % (WIDTH / PIXEL_SIZE)) * PIXEL_SIZE;
            fruit->y = (rand() % (HEIGHT / PIXEL_SIZE)) * PIXEL_SIZE;
            addTail(snake);
        }

        RenderSnake(snake, renderer, (struct Color){255, 255, 255, 255}, PIXEL_SIZE);
        RenderFruit(fruit, renderer, (struct Color){255, 0, 0, 255}, PIXEL_SIZE);

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    for (int i = 0; i < snake->length; i++)
    {
        printf("x: %d, y: %d\n", snake->tail[i].x, snake->tail[i].y);
    }

    free(snake->tail);
    free(snake);
    free(fruit);

    return 0;
}
