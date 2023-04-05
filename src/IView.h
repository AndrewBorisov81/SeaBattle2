#pragma once

#include <vector>

class Cell;
class Ship;

class IView {
public:
    using CellsList = std::vector<std::shared_ptr<Cell>>;
    using ShipsList = std::vector<std::shared_ptr<Ship>>;
     
    virtual void updateView(const CellsList& board,
         const ShipsList& ships) = 0;
    virtual bool init(const CellsList& board, 
        const ShipsList& ships, int rows, int columns) = 0;
    virtual void show(const CellsList& board) = 0;
    virtual void show(const CellsList& board, 
        const ShipsList& ships, 
            int rows, int columns) = 0;
    virtual ~IView() {}
};
