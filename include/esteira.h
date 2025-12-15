#ifndef ESTEIRA_H
#define ESTEIRA_H

#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../include/sentido.h"
#include "../include/ore.h"

class Esteira
{
    private:

    float px = 0;
    float py = 0;
    ALLEGRO_BITMAP* cSprite = nullptr;

    Sentidos sentido = UP;

    float rotation;

    public:

    void set_pos(float x, float y);
    void set_pos(int x, int y);

    std::vector<float> get_pos();

    void set_sentido();
    void set_rotation(float rotate);
    void set_sprite(ALLEGRO_BITMAP* sprite);
    void draw_esteira();
    void update_esteira(std::vector<Ore>* ores);

    bool rect_overlap(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);

};


#endif