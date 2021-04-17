
#pragma once

#include "CellularGrid.h"

namespace GameOfLife
{
    void run (const CellularGrid& seed,
              int numberOfGenerations,
              int msBetweenGenerations);

    void evolve (CellularGrid& seed);
};
