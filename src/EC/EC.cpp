#include "EC.h"

// Component methods

void Component::init() {
}

void Component::quick_update() {
}

void Component::update() {
}

void Component::late_update() {
}

void Component::draw() {
}

Component::~Component() {
}

// Entity methods

Entity::Entity(Entity_manager& _manager) : manager(_manager) {
    active = true;
}

void Entity::quick_update() {
    for (auto& c : compopnents_vector) {
        c->quick_update();
    }
}

void Entity::update() {
    for (auto& c : compopnents_vector) {
        c->update();
    }
}

void Entity::late_update() {
    for (auto& c : compopnents_vector) {
        c->late_update();
    }
}

void Entity::draw() {
    for (auto& c : compopnents_vector) {
        c->draw();
    }
}

bool Entity::is_active() {
    return active;
}

void Entity::set_inactive() {
    active = false;
}

bool Entity::has_group(group group_bitset) {
    return groups_bitset[group_bitset];
}

void Entity::add_group(group new_group) {
    groups_bitset[new_group] = true;
    manager.add_to_group(this, new_group);
}

void Entity::remove_group(group to_rmv) {
    groups_bitset[to_rmv] = false;
}

// Manager methods

void Entity_manager::quick_update() {
    for (auto& e : entities_vector) {
        e->quick_update();
    }
}

void Entity_manager::update() {
    for (auto& e : entities_vector) {
        e->update();
    }
}

void Entity_manager::late_update() {
    for (auto& e : entities_vector) {
        e->late_update();
    }
}

void Entity_manager::draw() {
    for (auto& e : entities_vector) {
        e->draw();
    }
}

void Entity_manager::remove_inactive() {

    for (auto i = 0; i < max_groups; ++i) {

        auto& v(grouped_entities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v),
                               [i](Entity* entity) {
                                   return !entity->is_active() ||
                                          !entity->has_group(i);
                               }),
                std::end(v));
    }

    entities_vector.erase(
        std::remove_if(std::begin(entities_vector), std::end(entities_vector),
                       [](const std::unique_ptr<Entity>& entity) {
                           return !(entity->is_active());
                       }),
        std::end(entities_vector));
}

void Entity_manager::add_to_group(Entity* entity, group grp) {
    grouped_entities[grp].emplace_back(entity);
}

std::vector<Entity*>& Entity_manager::get_group(group grp) {
    return grouped_entities[grp];
}

Entity& Entity_manager::add_entity() {

    Entity*                 e = new Entity(*this);
    std::unique_ptr<Entity> temp_ptr{e};

    entities_vector.emplace_back(std::move(temp_ptr));

    return *e;
}