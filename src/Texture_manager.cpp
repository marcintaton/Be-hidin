#include "Texture_manager.h"

SDL_Texture* Texture_manager::load_texture(const char* file_name) {

    SDL_Surface* surface = IMG_Load(file_name);
    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(Game_controler::renderer.get(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

void Texture_manager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst) {

    SDL_RenderCopy(Game_controler::renderer.get(), texture, &src, &dst);
}