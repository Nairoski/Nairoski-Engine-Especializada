#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../include/ore.h"

void Ore::ore_init(int max_ore)
{
    maxOre = max_ore;
    cOre = max_ore;
}

void Ore::set_pos(float x, float y)
{
    px = x;
    py = y;
}

ALLEGRO_BITMAP* Ore::get_sprite()
{
    return cSprite;
}

OreSource Ore::get_source()
{
    return source;
}
void Ore::set_source(OreSource s)
{
    source = s;
}

std::vector<float> Ore::get_pos() 
{
    std::vector<float> pos_vec;

    pos_vec.push_back(px);
    pos_vec.push_back(py);

    return pos_vec;
}
    
void Ore::set_sprite(ALLEGRO_BITMAP* sprite)
{
    cSprite = sprite;
}

void Ore::mine()
{
    cOre = cOre - 1;
}

void Ore::draw_ore()
{
    al_draw_bitmap(cSprite, px, py, 0);
}

void Ore::set_ore_type(OreType ore_type)
{
    type = ore_type;
}

OreType Ore::get_ore_type()
{
    return type;
}
