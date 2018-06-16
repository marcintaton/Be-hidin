#include "Item.h"

Item::Item() {
}

Item::Item(int _id) {
    id = _id;
}

Item::Item(int _id, bool quest_item) {
    id            = _id;
    is_quest_item = quest_item;
}

Item::~Item() {
}
