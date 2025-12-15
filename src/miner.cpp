#include "../include/miner.h"

#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/sentido.h"
#include "../include/itens.h"

#include "../include/ore.h"

void Miner::set_pos(float x, float y)
{
    px = x;
    py = y;
}

void Miner::set_pos(int x, int y)
{
    px = (float) x;
    py = (float) y;
}

std::vector<float> Miner::get_pos()
{
    std::vector<float> pos_vec;

    pos_vec.push_back(px);
    pos_vec.push_back(py);

    return pos_vec;
}

void Miner::miner_update(std::vector<Ore>* ores)
{
    timer += 1.0f / 60.0f;

    if (timer < spawn_delay) return;

    timer = 0.0f;  // Reset do timer

    float spawn_x = px;
    float spawn_y = py;
    const float OFFSET = 32.0f; // Distancia de saida

    switch (sentido)
    {
    case UP:
        spawn_y -= OFFSET;
        break;
    case DOWN:
        spawn_y += OFFSET;
        break;
    case LEFT:
        spawn_x -= OFFSET;
        break;
    case RIGHT:
        spawn_x += OFFSET;
        break;
    }

    std::vector<Ore> novos_ores;

    for (Ore& ore : *ores)
    {
        if (ore.get_source() != NATURAL) continue;

        auto pos = ore.get_pos();
        float ox = pos[0];
        float oy = pos[1];

        float ow = 32;
        float oh = 32;

        OreType type = ore.get_ore_type();

        if (rect_overlap(px, py, 64, 64, ox, oy, ow, oh))
        {
            switch (type)
            {
            case IRON: {
                Ore iron_ore;
                iron_ore.set_source(GENERATED);
                iron_ore.ore_init(1);
                iron_ore.set_sprite(ore.get_sprite());
                iron_ore.set_ore_type(ore.get_ore_type());
                iron_ore.set_pos(spawn_x, spawn_y);

                novos_ores.push_back(iron_ore);

                break;
            }
            case COPPER: {
                Ore copper_ore;
                copper_ore.set_source(GENERATED);
                copper_ore.ore_init(1);
                copper_ore.set_sprite(ore.get_sprite());
                copper_ore.set_ore_type(ore.get_ore_type());
                copper_ore.set_pos(spawn_x, spawn_y);

                novos_ores.push_back(copper_ore);

                break;
            }
            }
        }
    }

    for (Ore& o : novos_ores)
    {
        ores->push_back(o);
    }

}

void Miner::set_rotation(float rotate)
{
    rotation = rotate;
}

void Miner::set_sprite(ALLEGRO_BITMAP* sprite)
{
    cSprite = sprite;
}

void Miner::set_sentido(Sentidos s)
{
    sentido = s;
}

void Miner::draw_miner()
{
    float w = al_get_bitmap_width(cSprite);
    float h = al_get_bitmap_height(cSprite);
    //al_draw_bitmap(cSprite, px, py, 0);
    al_draw_rotated_bitmap(cSprite, w/2, h/2, px + 32, py + 32, rotation, 0);
}

// =====================================================================     Helper     =====================================================================

bool Miner::rect_overlap(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh)
{
    return ax < bx + bw && ax + aw > bx && ay < by + bh && ay + ah > by;
}

