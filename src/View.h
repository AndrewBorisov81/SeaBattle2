#pragma once
#include "IView.h"
#include "Cell.h"
#include "Ship.h"

#include <vector>
#include <memory>
class View : public IView {
public:
    View() = default;
    View(const CellsList& board, 
        const ShipsList& ships, int rows, int columns);
    virtual ~View() = default;
    bool init(const CellsList& board, 
        const ShipsList& ships, 
            int rows, int columns) override;
    void updateView(const CellsList& board,
         const ShipsList& ships) override;
    void show(const CellsList& board) override;
    void show(const CellsList& board, 
        const ShipsList& ships, 
            int rows, int columns) override;
    void clear();

private:
   CellsList m_board;
   ShipsList m_ships;
   int m_rows;
   int m_columns;

   const char* getChar(std::shared_ptr<Cell> cell);
   const char* getShipChar(std::shared_ptr<Cell> cell);
};
