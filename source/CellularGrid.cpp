
#include "CellularGrid.h"
#include <iostream>

CellularGrid::CellularGrid (int width, int height)
{
    Wid = width;
    Hei = height;
    int s = Wid * Hei * sizeof(char);
    cell = new char[s];
    memset(cell, 0, s);
}

CellularGrid::~CellularGrid() {
    try
    {
        free(cell);
    }
    catch (const std::exception& e)
    {
        std::cout << "ExceptionCaught" << std::endl;
    }
}

void CellularGrid::killCell (int x, int y)
{
    cell[x + y * Wid] = '-';
}

void CellularGrid::reviveCell (int x, int y)
{
    cell[x + y * Wid] = '*';
}

bool CellularGrid::isCellAlive (int x, int y) const
{
    if (cell[x + y * Wid] == '*') {
        return true;
    }
    else {
        return false;
    }
}

int CellularGrid::countLivingCellNeighbours (int x, int y) const
{
    int n = 0, ni, nz;
    for (int i = -1; i < 2; i++) {
        for (int z = -1; z < 2; z++) {
            if (!i && !z) continue;
            nz = (Wid + x + z) % Wid;
            ni = (Hei + y + i) % Hei;
            n += cell[nz + ni * Wid] == '*' ? 1 : 0;
        }
    }
    return n;
}

int CellularGrid::getWidth() const
{
    return Wid;
}

int CellularGrid::getHeight() const
{
    return Hei;
}
