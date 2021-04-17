
#include "GameOfLife.h"

#include <iostream>
#include <chrono>
#include <thread>

void GameOfLife::run (const CellularGrid& seed,
                      int numberOfGenerations,
                      int msBetweenGenerations)
{
    auto grid {seed};
    const auto aliveCharacter {'*'};
    const auto deadCharacter {'-'};

    for (auto i {0}; i < numberOfGenerations; ++i)
    {
        std::system ("cls||clear");

        for (auto x {0}; x < grid.getWidth(); ++x)
        {
            for (auto y {0}; y < grid.getHeight(); ++y)
            {
                std::cout << (grid.isCellAlive (x, y) ? aliveCharacter : deadCharacter);
            }

            std::cout << "\n";
        }

        evolve (grid);

        std::this_thread::sleep_for (std::chrono::milliseconds {msBetweenGenerations});
    }
    grid.~CellularGrid();
}

void GameOfLife::evolve(CellularGrid& grid)
{
    for (auto x{ 0 }; x < grid.getWidth(); ++x) {
        for (auto y{ 0 }; y < grid.getHeight(); ++y) {
            int count = grid.countLivingCellNeighbours(x, y);
            if (count == 3) {
                grid.reviveCell(x, y);
            }
            else if (count < 2) {
                grid.killCell(x, y);
            }
            count = 0;
        }
    }
}