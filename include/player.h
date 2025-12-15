#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
    float px = 0;
    float py = 0;
    ALLEGRO_BITMAP* cSprite = nullptr;

    public:

    void set_pos(float x, float y);
    std::vector<float> get_pos();

    void set_sprite(ALLEGRO_BITMAP* sprite);
    void draw_player();

    void move_update(bool player_up, bool player_down, bool player_left, bool player_right);
};

#endif