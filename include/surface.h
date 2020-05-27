#ifndef SURFACE_H
#define SURFACE_H

#include<SDL2/SDL.h>
#ifdef USE_IMG
//Include SDL2_Image
#endif
#include<stdexcept>

namespace sdl2_cpp {
  class Surface {
    private:
      SDL_Surface* surface;
    public:
      Surface(std::string& path);
      ~Surface();
      SDL_Surface* getSurface() noexcept;
  };
}

#endif
