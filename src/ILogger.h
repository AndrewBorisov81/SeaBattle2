#pragma once

#include <vector>

class Cell;
class Ship;

class ILogger {
public:
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships) = 0;
    virtual ~ILogger() = default;
};
