#include "Player_factory.h"
#include "../EC/Components.h"
#include "../Singletons/Player.h"

extern Entity_manager manager;

class Player;

void Player_factory::create(double      transform_x,
                            double      transform_y,
                            double      transform_h,
                            double      transform_w,
                            double      transform_scale,
                            std::string sprite_file_path,
                            bool        sprite_animated) {

    if (Player::Get_instance() == nullptr) {

        auto& new_player(manager.add_entity());

        new_player.add_component<Transform_component>(50, 50, 32, 32, 1);
        new_player.add_component<Sprite_component>(sprite_file_path.c_str(),
                                                   true);
        new_player.add_component<Input_controller>();
        new_player.add_component<Collider_component>("player");
        new_player.add_component<State_machine>("player");
        new_player.add_component<Bonus_controller>();
        new_player.add_group(Game_controler::g_players);

        Player::Set_instance(&new_player);
    }
}