#include "EC.h"

// Component methods

void Component::init() {
}

void Component::update() {
}

void Component::draw() {
}

Component::~Component() {
}

// Entity methods

void Entity::update() {
    for (auto& c : compopnents_vector) {
        c->update();
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
// Manager methods

void Entity_manager::update() {
    for (auto& e : entities_vector) {
        e->update();
    }
}

void Entity_manager::draw() {
    for (auto& e : entities_vector) {
        e->draw();
    }
}

void Entity_manager::remove_inactive() {
    entities_vector.erase(
        std::remove_if(std::begin(entities_vector), std::end(entities_vector),
                       [](const std::unique_ptr<Entity>& entity) {
                           return !(entity->is_active());
                       }),
        std::end(entities_vector));
}

Entity& Entity_manager::add_entity() {

    Entity*                 e = new Entity();
    std::unique_ptr<Entity> temp_ptr{e};

    entities_vector.emplace_back(std::move(temp_ptr));

    return *e;
}