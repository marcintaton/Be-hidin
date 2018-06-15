#include "Game_controler.h"
#include "Collision.h"
#include "EC/Components.h"
#include "EC/EC.h"
#include "Factories/Factories.h"
#include "Singletons/Singletons.h"
#include "Texture_manager.h"
#include "Vector_2D.h"

const char* map_tileset = "assets/map/tileset.png";

std::unique_ptr<Tile_map> map;

std::unique_ptr<SDL_Renderer, SDL_renderer_destroyer> Game_controler::renderer =
    nullptr;

Entity_manager manager;

SDL_Event Game_controler::event;

auto&                 map_tiles(manager.get_group(Game_controler::g_map));
auto&                 players(manager.get_group(Game_controler::g_players));
std::vector<Entity*>& enemies(manager.get_group(Game_controler::g_enemies));
std::vector<Entity*>& map_obj(manager.get_group(Game_controler::g_map_binded));
std::vector<Entity*>& projectiles(
    manager.get_group(Game_controler::g_projectiles));
std::vector<Entity*>& colliders(manager.get_group(Game_controler::g_colliders));
std::vector<Entity*>& pickable(manager.get_group(Game_controler::g_pickable));

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

        renderer.reset(
            SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));
        if (renderer.get()) {
            std::cout << "renderer initialized" << std::endl;
            SDL_SetRenderDrawColor(renderer.get(), 0, 128, 255, 255);
        }

        running = true;
    } else {
        running = false;
    }

    Player_factory::create(50, 50, 32, 32, 1, "assets/animations/player.png",
                           true);

    Turret_enemy_factory::create(1250, 545, 32, 32, 1,
                                 "assets/textures/turret.png", "enemy_turret",
                                 "assets/textures/projectile.png", 1);

    Bonus_factory::create_speed_bonus(300, 450, 32, 32, 0.5,
                                      "assets/textures/bonus.png", "bonus");
    Bonus_factory::create_invis_bonus(700, 530, 32, 32, 0.5,
                                      "assets/textures/bonus.png", "bonus");
    Bonus_factory::create_freeze_bonus(900, 530, 32, 32, 0.5,
                                       "assets/textures/bonus.png", "bonus");

    map.reset(new Tile_map(map_tileset, 1, 32));

    map->load_map("assets/map/level.map", 50, 40, 0, -20);

    Camera::Create_instance(
        &(Player::Get_instance())->get_component<Transform_component>(),
        map_tiles, colliders, map_obj, width, height);
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

    manager.remove_inactive();
    manager.quick_update();
    manager.update();
    manager.late_update();

    Camera::Get_instance()->update();
}

void Game_controler::render() {

    SDL_RenderClear(renderer.get());

    for (auto& t : map_tiles) {
        t->draw();
    }

    for (auto& p : players) {
        p->draw();
    }

    for (auto& e : enemies) {
        e->draw();
    }

    for (auto& p : pickable) {
        p->draw();
    }

    for (auto& p : projectiles) {
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
