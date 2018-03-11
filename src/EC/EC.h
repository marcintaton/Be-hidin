#ifndef EC_H
#define EC_H

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Component;
class Entity;

using component_id = std::size_t;

inline component_id get_component_type_id() {
    static component_id last_id = 0;
    return last_id++;
}

template <typename T>
inline component_id get_component_type_id() noexcept {
    static component_id type_id = get_component_type_id();
    return type_id;
}

constexpr std::size_t max_components = 32;

using component_bitset = std::bitset<max_components>;
using component_array  = std::array<Component*, max_components>;

// Component class

class Component {

   public:
    Entity*      parent_entity;
    virtual void init();
    virtual void update();
    virtual void draw();

    virtual ~Component();
};

// Entity class

class Entity {

   private:
    bool                                    active;
    std::vector<std::unique_ptr<Component>> compopnents_vector;
    component_array                         components_array;
    component_bitset                        components_bitset;

   public:
    Entity();
    void update();
    void draw();
    bool is_active();
    void set_inactive();

    template <typename T>
    bool has_component() const {
        return components_bitset[get_component_type_id<T>()];
    }

    template <typename T, typename... T_args>
    T& add_component(T_args&&... args) {

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
    T& get_component() const {
        auto ptr(components_array[get_component_type_id<T>()]);
        return *static_cast<T*>(ptr);
    }
};

// Entity_manger class

class Entity_manager {

   private:
    std::vector<std::unique_ptr<Entity>> entities_vector;

   public:
    void    update();
    void    draw();
    void    remove_inactive();
    Entity& add_entity();
};

#endif