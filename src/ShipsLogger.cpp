#include "ShipsLogger.h"
#include "Ship.h"

#include <iostream>

void ShipsLogger::update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships) 
{
    int allShips{0}, destroyedShips{0}, notDestroyedShips{0};
    for (const auto& ship: ships) {
        allShips++;
        if (ship->isDestroyed() == true) {
            destroyedShips++;
        }
    }
    notDestroyedShips = allShips - destroyedShips;
    std::cout << "All ships: " << allShips << " notDestroyedShips: " << notDestroyedShips << '\n'; 
}
