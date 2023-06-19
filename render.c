#include <stdlib.h>

#include "SDL2/SDL.h"
#include "snake.h"
#include "fruit.h"
#include "render.h"
#include "color.h"

void RenderSnake(struct Snake *snake, SDL_Renderer *renderer, struct Color color, int pxsize)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {snake->x, snake->y, pxsize, pxsize};
    SDL_RenderFillRect(renderer, &rect);

    for (int i = 0; i < snake->length; i++)
    {
        SDL_Rect rect = {snake->tail[i].x, snake->tail[i].y, pxsize, pxsize};
        SDL_RenderFillRect(renderer, &rect);
    }
}

void RenderFruit(struct Fruit *fruit, SDL_Renderer *renderer, struct Color color, int pxsize)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {fruit->x, fruit->y, pxsize, pxsize};
    SDL_RenderFillRect(renderer, &rect);
}
