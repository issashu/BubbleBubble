#ifndef SDLUTILS_H
#define SDLUTILS_H

#include "SDL2/SDL.h"

//Custom SDL deleter for pointer usage
struct sdl_deleter {
  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
  void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};

#endif //SDLUTILS_H
