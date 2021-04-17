
#include "Application.h"
#include "GameOfLife.h"

void Application::run()
{
    CellularGrid seed {8, 8};
    seed.reviveCell (4, 3);
    seed.reviveCell (5, 3);
    seed.reviveCell (6, 3);

    GameOfLife::run (seed, 10, 500);
}
