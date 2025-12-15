#include "../include/player.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>


void Player::move_update(bool player_up, bool player_down, bool player_left, bool player_right)
{
    if (player_up) { py = py - 10; }
    if (player_down) { py = py + 10; }
    if (player_left) { px = px - 10; }
    if (player_right) { px = px + 10; }
}

std::vector<float> Player::get_pos()
{
    std::vector<float> pos_vec;

    pos_vec.push_back(px);
    pos_vec.push_back(py);

    return pos_vec;
}

void Player::set_pos(float x, float y)
{
    px = x;
    py = y;
}

void Player::set_sprite(ALLEGRO_BITMAP* sprite) 
{
    cSprite = sprite;
}

void Player::draw_player()
{
    al_draw_bitmap(cSprite, px, py, 0);
}
