#include "../include/mouse.h"
#include <iostream>
#include <vector>
#include <allegro5/allegro_image.h>

#include "../include/miner.h"
#include "../include/esteira.h"
#include "../include/grid.h"

void Mouse::set_grid(Grid* grid)
{
    g = grid;
}

void Mouse::mouse_update(MouseItem item_picked, float x, float y)
{
    item = item_picked;
    px = x;
    py = y;
}


void Mouse::mouse_use_item(ALLEGRO_BITMAP* sprite, std::vector<Miner>* miners_vec, float ghost_rotation)  //       Usar Mineradora
{

    int m_x = px;
    int m_y = py;

    int gx = m_x / 64;
    int gy = m_y / 64;

    if (g->at(gx, gy).type == EMPTY)
    {
        Miner m;
        m.set_sprite(sprite);
        m.set_rotation(ghost_rotation);

        m.set_pos(gx * 64, gy * 64);
        miners_vec->push_back(m);

        g->at(gx, gy).type = _MINER;
        g->at(gx, gy).id = miners_vec->size() - 1;
    }
    
}
void Mouse::mouse_use_item(ALLEGRO_BITMAP* sprite, std::vector<Esteira>* esteiras_vec, float ghost_rotation) //    Usar Esteiras
{
    int m_x = px;
    int m_y = py;

    int gx = m_x / 32;
    int gy = m_y / 32;

    if (g->at(gx, gy).type == EMPTY)
    {
        Esteira est;
        est.set_sprite(sprite);
        est.set_rotation(ghost_rotation);
        est.set_sentido();

        est.set_pos(gx * 32, gy * 32);
        esteiras_vec->push_back(est);

        g->at(gx, gy).type = _ESTEIRA;
        g->at(gx, gy).id = esteiras_vec->size() - 1;
    }
}