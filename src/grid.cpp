#include "../include/grid.h"

Grid::Grid(int w, int h) : width(w), height(h)
{
    cells.resize(w * h);
}

bool Grid::in_bounds(int x, int y)
{
    return x >= 0 && y >= 0 && x < width && y < height;
}

Cell& Grid::at(int x, int y)
{
    return cells[y * width + x];
}
