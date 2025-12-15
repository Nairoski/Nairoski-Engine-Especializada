#ifndef MINER_H
#define MINER_H

#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/sentido.h"
#include "../include/itens.h"

#include "../include/ore.h"

class Miner
{
    private:

    float px = 0;
    float py = 0;
    ALLEGRO_BITMAP* cSprite = nullptr;

    Sentidos sentido = UP;
    float timer = 0.0f;                   // tempo acumulado
    float spawn_delay = 2.0f;             // tempo entre spawns (segundos)

    float rotation;

    float check_x = 0;
    float check_y = 0;


    public:

    void set_pos(float x, float y);
    void set_pos(int x, int y);

    std::vector<float> get_pos();

    bool rect_overlap(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);

    void set_rotation(float rotate);
    void set_sentido(Sentidos s);
    void set_sprite(ALLEGRO_BITMAP* sprite);
    void miner_update(std::vector<Ore>* ores);
    void draw_miner();

};

#endif