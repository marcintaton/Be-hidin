#include "Texture_manager.h"

std::unique_ptr<SDL_Texture, SDL_texture_destroyer>
Texture_manager::load_texture(const char* file_name) {

    std::unique_ptr<SDL_Surface, SDL_surface_destroyer> surface(
        IMG_Load(file_name));

    std::unique_ptr<SDL_Texture, SDL_texture_destroyer> texture(
        SDL_CreateTextureFromSurface(Game_controler::renderer.get(),
                                     surface.get()));

    return texture;
}