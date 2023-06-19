#include "SDL2/SDL.h"
#include "snake.h"
#include "fruit.h"
#include "color.h"

void RenderSnake(struct Snake *snake, SDL_Renderer *renderer, struct Color color, int pxsize);
void RenderFruit(struct Fruit *fruit, SDL_Renderer *renderer, struct Color color, int pxsize);
