#ifndef GRID_H
#define GRID_H

#include <vector>

enum CellType 
{
    EMPTY,
    _ORE,
    _MINER,
    _ESTEIRA
};

struct Cell
{
    CellType type = EMPTY;
    int id = -1;
};

class Grid
{
    public:
    int width;
    int height;
    int tile_size = 32;

    std::vector<Cell> cells;

    Grid(int w, int h);

    Cell& at(int x, int y);
    bool in_bounds(int x, int y);
};

#endif