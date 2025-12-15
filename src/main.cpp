#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

#include "../include/mouse.h"
#include "../include/player.h"
#include "../include/miner.h"
#include "../include/ore.h"
#include "../include/esteira.h"
#include "../include/grid.h"

#define SCREEN_W 1020  // Largura
#define SCREEN_H 720   // Altura

int main(int argc, char** argv)
{
    bool running = true;

    int tile_size = 32;

    Grid grid(64, 64);

    if (!al_init()) {std::cerr << "Falha ao iniciar o Allegro!" << std::endl; return -1;}
    if (!al_init_image_addon()) {std::cerr << "Falha ao inicializar o add-on de imagem!" << std::endl; return -1;}
    if (!al_install_keyboard()) {std::cerr << "Falha ao inicializar o teclado" << std::endl;return -1;}
    if (!al_install_mouse()) {std::cerr << "Falha ao inicializar o mouse" << std::endl; return -1;}
    if (!al_init_primitives_addon()) {std::cerr << "Falha ao inicializar o add-on de primitivas" << std::endl; return -1;}

    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
    if (!display){std::cout << "falha ao criar janela!" << std::endl; return -1;}





    ALLEGRO_BITMAP* person = al_load_bitmap("assets/SimplePerson.png");
    if (!person) {std::cerr << "Falha ao carregar a imagem!" << std::endl; al_destroy_display(display); return -1;}

    ALLEGRO_BITMAP* miner1 = al_load_bitmap("assets/Miner.png");
    if (!miner1) {std::cerr << "Falha ao carregar a imagem!" << std::endl; al_destroy_display(display); return -1;}

    ALLEGRO_BITMAP* esteira = al_load_bitmap("assets/Esteira.png");
    if (!esteira) {std::cerr << "Falha ao carregar a image!" << std::endl; al_destroy_display(display); return -1;}







    ALLEGRO_BITMAP* iron_ore = al_load_bitmap("assets/iron_ore.png");
    if (!iron_ore) {std::cerr << "Falhas ao carregar a imagem!" << std::endl; al_destroy_display(display); return -1;}

    ALLEGRO_BITMAP* copper_ore = al_load_bitmap("assets/copper_ore.png");
    if (!copper_ore) {std::cerr << "Falhas ao carregar a imagem!" << std::endl; al_destroy_display(display); return -1;}






    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);  // 60 FPS
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    // ------------------------ Player
    Player player;
    player.set_sprite(person);

    float player_x = 100, player_y = 100;

    bool player_up = false, player_down = false, player_right = false, player_left = false;
    player.set_pos(player_x, player_y);

    // -------------------------------

    // ----------------------- Miner

    std::vector<Miner> miners;

    // -----------------------------

    // ---------------------- Ores
    std::vector<Ore> ores;

    float ocx1 = 200;
    float ocy1 = 200;
    float ocRaio1 = 96;

    for (int x = -ocRaio1; x <= ocRaio1; x += 32)
    {
        for (int y = -ocRaio1; y <= ocRaio1; y += 32)
        {
            if (x*x + y*y <= ocRaio1*ocRaio1)
            {
                Ore ore;
                ore.set_ore_type(IRON);
                ore.ore_init(100);
                ore.set_sprite(iron_ore);
                ore.set_pos(ocx1 + x, ocy1 + y);
                ores.push_back(ore);
            }
        }
    }

    float ocx2 = 100;
    float ocy2 = 100;
    float ocRaio2 = 96;

    for (int x = -ocRaio2; x <= ocRaio2; x += 32)
    {
        for (int y = -ocRaio2; y <= ocRaio2; y += 32)
        {
            if (x*x + y*y <= ocRaio2*ocRaio2)
            {
                Ore ore;
                ore.set_ore_type(COPPER);
                ore.ore_init(100);
                ore.set_sprite(copper_ore);
                ore.set_pos(ocx1 + x, ocy1 + y);
                ores.push_back(ore);
            }
        }
    }
    // ----------------------------

    // --------------------- Esteira

    std::vector<Esteira> esteiras;

    // ----------------------------

    ALLEGRO_COLOR ghost = al_map_rgba_f(0.0, 1.0, 0.0, 1.0);

    Mouse mouse;
    MouseItem mouse_item = NOTHING;
    int mouse_x = 0, mouse_y = 0;
    float centro_x = 0, centro_y = 0;
    mouse.set_grid(&grid);

    // Angulos

    float ghost_rotation = 0.0f;
    const float ROT_STEP = ALLEGRO_PI / 2; // 90 graus;

    // -------

    ALLEGRO_EVENT ev;
    while (running)
    {
        al_wait_for_event(queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            al_clear_to_color(al_map_rgb(0, 20, 20));

            
            player.move_update(player_up, player_down, player_left, player_right);
            player.draw_player();

            for (Esteira& est : esteiras)
            {
                est.draw_esteira();
                est.update_esteira(&ores);
            }

            for (Ore ore : ores)
            {
                ore.draw_ore();
            }
            
            for (Miner& mine : miners)
            {
                mine.draw_miner();
                mine.miner_update(&ores);
            }

            switch (mouse_item) // Mostrar Fantasmas dos Itens Selecionados 
            {
                case MINER: {
                    float w = al_get_bitmap_width(miner1);
                    float h = al_get_bitmap_height(miner1);

                    al_draw_tinted_rotated_bitmap(miner1, ghost, w/2, h/2, mouse_x, mouse_y, ghost_rotation, 0);
                    break;
                }
                case ESTEIRA: {
                    float w = al_get_bitmap_width(esteira);
                    float h = al_get_bitmap_height(esteira);

                    al_draw_tinted_rotated_bitmap(esteira, ghost, w/2, h/2, mouse_x, mouse_y, ghost_rotation, 0);
                    break;
                }
            }
            

            al_flip_display();
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                running = false;
            }

            switch(ev.keyboard.keycode) { // Movimentação
                case ALLEGRO_KEY_W: player_up = true; break;
                case ALLEGRO_KEY_S: player_down = true; break;
                case ALLEGRO_KEY_A: player_left = true; break;
                case ALLEGRO_KEY_D: player_right = true; break;
            }

            switch (ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_1:
                    mouse_item = MINER;
                    break;
                case ALLEGRO_KEY_2:
                    mouse_item = ESTEIRA;
                    break;
                // Adicionar outros `case` aqui!

                case ALLEGRO_KEY_0:
                    mouse_item = NOTHING;
                    break;
                case ALLEGRO_KEY_R:
                    ghost_rotation += ROT_STEP;

                    if (ghost_rotation >= ALLEGRO_PI * 2)
                    {
                        ghost_rotation = 0.0f;
                    }

                    break;
            }

        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_W: player_up = false; break;
                case ALLEGRO_KEY_S: player_down = false; break;
                case ALLEGRO_KEY_A: player_left = false; break;
                case ALLEGRO_KEY_D: player_right = false; break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            running = false;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (ev.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)
            {
                std::cout << "Mouse Click Left" << std::endl;

                switch (mouse_item)
                {
                case MINER:
                    mouse.mouse_use_item(miner1, &miners, ghost_rotation);
                    break;
                case ESTEIRA:
                    mouse.mouse_use_item(esteira, &esteiras, ghost_rotation);
                    break;
                }
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            mouse.mouse_update(mouse_item, ev.mouse.x, ev.mouse.y);
            
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            centro_x = mouse_x - 32;
            centro_y = mouse_y - 32;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
        {
            al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
        }
    }

    al_destroy_bitmap(person);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

