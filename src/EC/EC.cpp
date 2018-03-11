#include "EC.h"

// Component methods

Component::~Component() {
}

void Component::init() {
}

void Component::update() {
}

void Component::draw() {
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

template <typename T>
bool Entity::has_component() const {
    return components_bitset[get_component_type_id<T>()];
}

template <typename T, typename... T_args>
T& Entity::add_component(T_args&&... args) {

    T* c(new T(std::forward<T_args>(args)...));

    c->parent_entity = this;

    std::unique_ptr<Component> temp_ptr{c};

    compopnents_vector.emplace_back(std::move(temp_ptr));

    components_array[get_component_type_id<T>()]  = c;
    components_bitset[get_component_type_id<T>()] = true;

    c->init();

    return *c;
}

template <typename T>
T& Entity::get_component() const {

    auto ptr(components_array[get_component_type_id<T>()]);
    return *static_cast<T*>(ptr);
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