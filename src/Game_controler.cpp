#include "Game_controler.h"
#include "Camera.h"
#include "Collision.h"
#include "EC/Components.h"
#include "EC/EC.h"
#include "Texture_manager.h"
#include "Tile_map.h"
#include "Vector_2D.h"

const char* map_tileset = "assets/map/tileset.png";

std::unique_ptr<Tile_map> map;

std::unique_ptr<SDL_Renderer, SDL_renderer_destroyer> Game_controler::renderer =
    nullptr;

Entity_manager manager;
auto&          new_player(manager.add_entity());

Camera* camera;

SDL_Event Game_controler::event;

auto& map_tiles(manager.get_group(Game_controler::g_map));
auto& players(manager.get_group(Game_controler::g_players));
auto& colliders(manager.get_group(Game_controler::g_colliders));

Game_controler::Game_controler() {
}

Game_controler::~Game_controler() {
}

void Game_controler::initialize(const char* title,
                                int         x_pos,
                                int         y_pos,
                                int         width,
                                int         height,
                                bool        fullscreen) {
    loop_cnt  = 0;
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL initialized" << std::endl;

        window.reset(
            SDL_CreateWindow(title, x_pos, y_pos, width, height, flags));
        if (window.get()) {
            std::cout << "window initialized" << std::endl;
        }

        renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));
        if (renderer.get()) {
            std::cout << "renderer initialized" << std::endl;
            SDL_SetRenderDrawColor(renderer.get(), 0, 128, 255, 255);
        }

        running = true;
    } else {
        running = false;
    }

    map.reset(new Tile_map(map_tileset, 1, 32));

    map->load_map("assets/map/level.map", 50, 40, 0, -20);

    new_player.add_component<Transform_component>(50, 50, 32, 32, 1);
    new_player.add_component<Sprite_component>("assets/animations/player.png",
                                               true);
    new_player.add_component<Input_controller>();
    new_player.add_component<Collider_component>("player");
    new_player.add_group(g_players);

    camera = new Camera(&new_player.get_component<Transform_component>(),
                        map_tiles, colliders, width, height);
}

void Game_controler::handle_events() {

    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game_controler::update() {

    SDL_Rect  p_col = new_player.get_component<Collider_component>().collider;
    Vector_2D player_pos =
        new_player.get_component<Transform_component>().position;

    manager.remove_inactive();
    manager.update();

    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;
        if (Collision::aabb(c_col, p_col)) {

            Vector_2D offset;
            offset.zero();

            new_player.get_component<Transform_component>().position =
                player_pos + offset;
        }
    }

    camera->update();
}

void Game_controler::render() {

    SDL_RenderClear(renderer.get());

    for (auto& t : map_tiles) {
        t->draw();
    }

    for (auto& p : players) {
        p->draw();
    }

    for (auto& c : colliders) {
        c->draw();
    }

    // manager.draw();

    SDL_RenderPresent(renderer.get());
}

void Game_controler::clear() {

    SDL_Quit();

    std::cout << "Game cleaned" << std::endl;
}

bool Game_controler::is_running() {
    return running;
}
