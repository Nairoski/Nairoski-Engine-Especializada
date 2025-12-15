#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/sentido.h"
#include <cmath>

#include "../include/esteira.h"
#include "../include/ore.h"


void Esteira::set_pos(float x, float y)
{
    px = x;
    py = y;
}

void Esteira::set_pos(int x, int y)
{
    px = (float) x;
    py = (float) y;
}

std::vector<float> Esteira::get_pos()
{
    std::vector<float> pos_vec;

    pos_vec.push_back(px);
    pos_vec.push_back(py);

    return pos_vec;
}

void Esteira::set_sprite(ALLEGRO_BITMAP* sprite)
{
    cSprite = sprite;
}
void Esteira::draw_esteira()
{
    float w = al_get_bitmap_width(cSprite);
    float h = al_get_bitmap_height(cSprite);
    //al_draw_bitmap(cSprite, px, py, 0);
    al_draw_rotated_bitmap(cSprite, w/2, h/2, px + 32, py + 32, rotation, 0);
}

void Esteira::set_rotation(float rotate)
{
    rotation = rotate;
}

void Esteira::set_sentido()
{
    float r = fmod(rotation, ALLEGRO_PI * 2);
    if (r < 0) r += ALLEGRO_PI * 2;

    const float EPS = 0.01f;

    if (fabs(r - 0.0f) < EPS)
    {
        sentido = UP;
    }
    else if (fabs(r - ALLEGRO_PI / 2) < EPS)
    {
        sentido = RIGHT;
    }
    else if (fabs(r - ALLEGRO_PI) < EPS)
    {
        sentido = DOWN;
    }
    else if (fabs(r - 3 * ALLEGRO_PI / 2) < EPS)
    {
        sentido = LEFT;
    }
}

void Esteira::update_esteira(std::vector<Ore>* ores)
{
    const float SPEED = 1.0f;

    for (Ore& ore : *ores)
    {
        if (ore.get_source() == GENERATED)
        {
            auto pos = ore.get_pos();
            float ox = pos[0];
            float oy = pos[1];

            if (!rect_overlap(px, py, 64, 64, ox, oy, 32, 32)) continue;

            switch (sentido)
            {
            case UP:{ore.set_pos(ox, oy - SPEED); break;}
            case DOWN:{ore.set_pos(ox, oy + SPEED); break;}
            case LEFT:{ore.set_pos(ox - SPEED, oy); break;}
            case RIGHT:{ore.set_pos(ox + SPEED, oy); break;}
            }
        }

    }

    

}

bool Esteira::rect_overlap(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh)
{
    return ax < bx + bw && ax + aw > bx && ay < by + bh && ay + ah > by;
}
