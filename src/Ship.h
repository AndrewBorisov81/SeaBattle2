#pragma once

#include "Cell.h"

#include <memory>
#include <vector>

class Position;
  
class Ship {
public:
    using CellsList = std::vector<std::shared_ptr<Cell>>;

    enum class Type { 
        singleDeckShip = 1, 
        doubleDeckShip = 2, 
        threeDeckShip = 3, 
        fourDeckShip = 4, 
    };

    Ship();
    Ship(Type type, std::vector<std::shared_ptr<Cell>> position, bool isHorizontal);
    ~Ship();

    static std::shared_ptr<Ship> create(Type type, 
        std::vector<std::shared_ptr<Cell>> position, bool isHorizontal);

    void hit(int row, int col);

    void setType(Type type);
    Type getType() const;
    bool isDestroyed() const;
    bool isHit() const;
    bool isHorizontal() const;
    void setHealth();

    const std::vector<std::shared_ptr<Cell>>& getPosition() const;
    Cell::Type getTypeInCell(const std::shared_ptr<Cell> cell);

private:
   std::vector<std::shared_ptr<Cell>> m_position;
   Type m_type;
   bool m_isHorizontal;
   bool m_isDestroyed;
   int m_health;
   int m_isHit;

   void destroy();
};
