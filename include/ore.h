#ifndef ORE_H
#define ORE_H

#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

enum OreSource
{
    NATURAL,
    GENERATED
};

enum OreType
{
    IRON,
    COPPER
};

class Ore
{
    private:

    float px = 0;
    float py = 0;
    int maxOre;
    int cOre;

    ALLEGRO_BITMAP* cSprite = nullptr;
    OreType type;
    OreSource source = NATURAL;

    public:

    void ore_init(int max_ore);

    void set_pos(float x, float y);
    std::vector<float> get_pos();
    
    void set_sprite(ALLEGRO_BITMAP* sprite);
    ALLEGRO_BITMAP* get_sprite();

    void mine();

    void draw_ore();

    void set_ore_type(OreType ore_type);
    OreType get_ore_type();
    OreSource get_source();
    void set_source(OreSource s);
};

#endif