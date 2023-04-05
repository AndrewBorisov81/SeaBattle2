#include "Ship.h"

Ship::Ship()
    : m_type{Type::singleDeckShip},
      m_isDestroyed{false},
      m_isHorizontal{true},
      m_health{0}, 
      m_isHit{false}
{
    setHealth();
}

Ship::Ship(Type type, std::vector<std::shared_ptr<Cell>> position, bool isHorizontal) 
    : m_type{type}, m_isHorizontal{isHorizontal},
      m_health{0}, m_isHit{false}, m_position{position} {
    setHealth();
}

Ship::~Ship() {

}

std::shared_ptr<Ship> Ship::create(Type type, 
        std::vector<std::shared_ptr<Cell>> position, bool isHorizontal) {
    return std::make_unique<Ship>(type, position, isHorizontal);
}

void Ship::hit(int row, int col) {
    m_health--;
    m_isHit = true;

    for (auto &cell: m_position) {
        if(cell->getRow() == row && cell->getColumn() == col) {
            cell->setType(Cell::Type::Hit);
        }
    }
    
    if(m_health <= 0) {
       for (auto &cell: m_position) {
           cell->setType(Cell::Type::DestroyedShip);
       }

       destroy();
    }
}

void Ship::setType(Type type) {
    m_type = type;
}

Ship::Type Ship::getType() const {
    return m_type;
}

void Ship::destroy() {
    m_isDestroyed = true;
}

bool Ship::isDestroyed() const {
    return m_isDestroyed;
}

bool Ship::isHorizontal() const {
    return m_isHorizontal;
}

bool Ship::isHit() const {
    return m_isHit;
}

const std::vector<std::shared_ptr<Cell>>& Ship::getPosition() const {
    return m_position;
}

Cell::Type Ship::getTypeInCell(const std::shared_ptr<Cell> cell) {
    Cell::Type cellType{Cell::Type::Ship};
    for (const auto &shipCell: m_position) {
        if(shipCell->getRow() == cell->getRow() && shipCell->getColumn() == cell->getColumn()) {
            return shipCell->getType();
        }
    }
    return cellType;
}

void Ship::setHealth() {
    switch(m_type) {
        case Type::fourDeckShip:
            m_health = 4;
            break;

        case Type::threeDeckShip:
            m_health = 3;
            break;

        case Type::doubleDeckShip:
            m_health = 2;
            break;

        case Type::singleDeckShip:
            m_health = 1;
            break;
    }
}
