#include <functional>
#include <memory>
#include "Game_controler.h"

std::unique_ptr<Game_controler> game_controler = nullptr;

std::vector<std::function<void()>> level_creator;

void game_loop() {

    const int max_FPS            = 60;
    const int max_frame_duration = 1000 / max_FPS;

    uint32_t frame_start;
    int      frame_duration;

    while (game_controler->is_running()) {

        frame_start = SDL_GetTicks();

        game_controler->handle_events();
        game_controler->update();
        game_controler->render();

        frame_duration = SDL_GetTicks() - frame_start;

        if (frame_duration < max_frame_duration) {
            SDL_Delay(max_frame_duration - frame_duration);
        }
    }
}

void init_creator() {

    level_creator.push_back([] { game_controler->create_lvl_1(); });
    level_creator.push_back([] { game_controler->create_lvl_2(); });
}

int main(int argc, char* argv[]) {

    init_creator();

    game_controler.reset(new Game_controler());

    game_controler->initialize("C&D", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 800, 640, false);

    for (auto& create : level_creator) {

        create();
        game_loop();

        if (game_controler->quit == true) {
            break;
        }
    }

    game_controler->clear();

    return 0;
}
