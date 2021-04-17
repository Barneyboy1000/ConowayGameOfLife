
#pragma once

#include <vector>

class CellularGrid
{
public:
    CellularGrid (int width, int height);
    ~CellularGrid();

    void killCell (int x, int y);
    void reviveCell (int x, int y);
    bool isCellAlive (int x, int y) const;
    int countLivingCellNeighbours (int x, int y) const;

    int getWidth() const;
    int getHeight() const;

private:
    int Wid, Hei;
    char* cell;
};
