//
// Created by Issashu Greybeard on 24.08.24.
//

#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <SDL2/SDL.h>

struct sdl_deleter
{
  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); SDL_Quit();}
  void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};


#endif //SDLUTILS_H
