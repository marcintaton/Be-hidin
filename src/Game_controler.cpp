#include "Game_controler.h"
#include "Game_object.h"
#include "Texture_manager.h"
#include "Tile_map.h"

std::unique_ptr<Game_object> player;
std::unique_ptr<Tile_map>    map;

std::unique_ptr<SDL_Renderer, SDL_renderer_destroyer> Game_controler::renderer =
    nullptr;

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

    player.reset(new Game_object("assets/player.png", 10, 20));
    map.reset(new Tile_map());
}

void Game_controler::handle_events() {

    SDL_Event event;
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

    loop_cnt++;
    player->update();

    // call update methods for all objects
}

void Game_controler::render() {

    SDL_RenderClear(renderer.get());
    // stuff to render
    map->draw_map();
    player->render();

    SDL_RenderPresent(renderer.get());
}

void Game_controler::clear() {

    // SDL_DestroyWindow(window.get());
    // SDL_DestroyRenderer(renderer.get());
    SDL_Quit();

    std::cout << "Game cleaned" << std::endl;
}

bool Game_controler::is_running() {
    return running;
}
