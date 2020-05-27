#include "surface.h"

namespace sdl2_cpp {
  Surface::Surface(std::string& path) {
    if (path.size() < 5) {
      throw std::runtime_error("Illegal filename.");
    }
    std::string suffix = path.substr(path.size() - 4, 4);
    if (suffix == ".bmp") {
      this->surface = SDL_LoadBMP(path.c_str());
    }
    #ifdef USE_IMG
    else if (suffix == ".png") {
      this->surface = IMG_Load(path.c_str());
    }
    #endif
    else {
      #ifdef USE_IMG
      throw std::runtime_error("Illefal file suffix. Supported: .bmp .png");
      #else
      throw std::runtime_error("Illegal file suffix. Supported: .bmp");
      #endif
    }
    if (!this->surface) {
      throw std::runtime_error(std::string("Could not create surface: ") + std::string(SDL_GetError()));
    }
  }

  Surface::~Surface() {
    if(this->surface) {
      SDL_FreeSurface(this->surface);
    }
  }

  SDL_Surface* Surface::getSurface() noexcept {
    return this->surface;
  }
}
