#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"
#include "EC.h"
#include "Sprite_component.h"
#include "Transform_component.h"

class Sprite_component;

class Tile_component : public Component {

   private:
   public:
    Transform_component* transform;
    Sprite_component*    sprite;

    SDL_Rect    rect;
    int         tile_ID;
    const char* path;

    Tile_component() = default;
    Tile_component(int x, int y, int width, int height, int id);

    void init() override;
};

#endif