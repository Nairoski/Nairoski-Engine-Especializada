#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <vector>

#include "../include/miner.h"
#include "../include/esteira.h"
#include "../include/grid.h"

#ifndef MOUSE_H
#define MOUSE_H

enum MouseItem
{
    NOTHING = 0,
    MINER = 1,
    ESTEIRA = 2
};

class Mouse
{
    private:
    MouseItem item;
    float px;
    float py;
    Grid* g = nullptr;

    public:
    void set_grid(Grid* grid);
    void mouse_update(MouseItem item_picked, float x, float y);
    void mouse_use_item(ALLEGRO_BITMAP* sprite, std::vector<Miner>* miners_vec, float ghost_rotation);
    void mouse_use_item(ALLEGRO_BITMAP* sprite, std::vector<Esteira>* esteiras_vec, float ghost_rotation);

};

#endif