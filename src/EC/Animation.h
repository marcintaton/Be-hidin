#ifndef ANIMATION_H
#define ANIMATION_H

class Animation {

   public:
    int index;
    int frame_num;
    int animation_delay;

    Animation() = default;
    Animation(int _index, int _frame_num, int _animation_delay) {
        index           = _index;
        frame_num       = _frame_num;
        animation_delay = _animation_delay;
    }
};

#endif