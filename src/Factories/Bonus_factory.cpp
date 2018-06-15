#include "Bonus_factory.h"
#include <functional>
#include "../Bonuses/Bonuses.h"
#include "../EC/Components.h"
#include "../EC/EC.h"
#include "../Singletons/Player.h"

extern Entity_manager manager;

std::function<void()> Bonus_factory::create_speed = []() {
    Player::Get_instance()->get_component<Bonus_controller>().add_bonus(
        new Speed_bonus(
            &Player::Get_instance()->get_component<Bonus_controller>()));
};

std::function<void()> Bonus_factory::create_invis = []() {
    Player::Get_instance()->get_component<Bonus_controller>().add_bonus(
        new Invis_bonus(
            &Player::Get_instance()->get_component<Bonus_controller>()));
};

std::function<void()> Bonus_factory::create_freeze = []() {
    Player::Get_instance()->get_component<Bonus_controller>().add_bonus(
        new Freeze_bonus(
            &Player::Get_instance()->get_component<Bonus_controller>()));
};

Entity& Bonus_factory::add_components(double      transform_x,
                                      double      transform_y,
                                      double      transform_h,
                                      double      transform_w,
                                      double      transform_scale,
                                      std::string sprite_path,
                                      std::string collider_tag) {

    auto& bonus(manager.add_entity());

    bonus.add_component<Transform_component>(
        transform_x, transform_y, transform_h, transform_w, transform_scale);
    bonus.add_component<Sprite_component>(sprite_path.c_str());
    bonus.add_component<Collider_component>("bonus");
    bonus.add_group(Game_controler::g_pickable);
    bonus.add_group(Game_controler::g_map_binded);

    return bonus;
}

void Bonus_factory::create_speed_bonus(double      transform_x,
                                       double      transform_y,
                                       double      transform_h,
                                       double      transform_w,
                                       double      transform_scale,
                                       std::string sprite_path,
                                       std::string collider_tag) {

    auto& bonus = Bonus_factory::add_components(
        transform_x, transform_y, transform_h, transform_w, transform_scale,
        sprite_path, collider_tag);
    bonus.add_component<Bonus_component>(Bonus_factory::create_speed);
}

void Bonus_factory::create_invis_bonus(double      transform_x,
                                       double      transform_y,
                                       double      transform_h,
                                       double      transform_w,
                                       double      transform_scale,
                                       std::string sprite_path,
                                       std::string collider_tag) {

    auto& bonus = Bonus_factory::add_components(
        transform_x, transform_y, transform_h, transform_w, transform_scale,
        sprite_path, collider_tag);
    bonus.add_component<Bonus_component>(Bonus_factory::create_invis);
}

void Bonus_factory::create_freeze_bonus(double      transform_x,
                                        double      transform_y,
                                        double      transform_h,
                                        double      transform_w,
                                        double      transform_scale,
                                        std::string sprite_path,
                                        std::string collider_tag) {

    auto& bonus = Bonus_factory::add_components(
        transform_x, transform_y, transform_h, transform_w, transform_scale,
        sprite_path, collider_tag);
    bonus.add_component<Bonus_component>(Bonus_factory::create_freeze);
}