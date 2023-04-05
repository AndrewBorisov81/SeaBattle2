#pragma once
#include <vector>

class Cell;
class Ship;

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) = 0;
};
