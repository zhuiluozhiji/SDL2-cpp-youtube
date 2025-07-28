#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL_rect.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object {
private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture* tex;
public:
    Object(){}
    SDL_Rect getDest()
};

#endif // OBJECT_H