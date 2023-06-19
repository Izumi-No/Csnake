

#include <stdlib.h>
#include <stdio.h>

#include "SDL2/SDL.h"

#include "snake.h"

#include "kbdlistener.h"

void ListenKeyboard(struct Snake *snake, SDL_Event *event)
{

    switch (event->key.keysym.sym)
    {
    case SDLK_w:
        if (snake->dir != DOWN)
        {
            snake->dir = UP;
            printf("UP\n");
        }
        break;
    case SDLK_s:
        if (snake->dir != UP)
        {
            snake->dir = DOWN;

            printf("DOWN\n");
        }
        break;
    case SDLK_a:
        if (snake->dir != RIGHT)
        {
            snake->dir = LEFT;

            printf("LEFT\n");
        }
        break;
    case SDLK_d:
        if (snake->dir != LEFT)
        {
            snake->dir = RIGHT;

            printf("RIGHT\n");
        }
        break;
    }
}