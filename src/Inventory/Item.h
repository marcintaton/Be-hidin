#pragma once

class Item {

   private:
   public:
    bool is_quest_item = false;
    int  id;

    Item();
    Item(int _id);
    Item(int _id, bool quest_item);
    ~Item();
};