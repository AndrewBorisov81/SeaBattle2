#include "View.h"
#include "Cell.h"
#include "Ship.h"

#include <iostream>

View::View(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) 
    : m_board{board}, m_ships{ships}, m_rows{rows}, m_columns{columns}
{

}

bool View::init(const std::vector<std::shared_ptr<Cell>>& board, 
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    m_board = board;
    m_ships = ships;
    m_rows = rows;
    m_columns = columns;
    return true;
}

void View::updateView(const std::vector<std::shared_ptr<Cell>>& board, 
    const std::vector<std::shared_ptr<Ship>>& ships) {
    m_board = board;
    m_ships = ships;
    show(m_board);
}

void View::show(const std::vector<std::shared_ptr<Cell>>& board) {
    const int numElements = board.size();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_columns; j++) {
            int indexElem = numElements/m_rows * i + j;
            std::shared_ptr<Cell> cell = board.at(indexElem);
            std::cout << getChar(cell) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void View::show(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    const int numElements = board.size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int indexElem = numElements/rows * i + j;
            std::shared_ptr<Cell> cell = board.at(indexElem);
            std::cout << getChar(cell) << " ";
        }
        std::cout << std::endl;
    }
}

void View::clear() {

}

const char* View::getChar(std::shared_ptr<Cell> cell) {
    const char* ch = "0";
    switch(cell->getType()) {
        case Cell::Type::Empty:
            ch = "0";
            break;
        case Cell::Type::Ship:
            ch = getShipChar(cell);
            break;
        case Cell::Type::Hit:
            ch = "x";   
            break;
        case Cell::Type::DestroyedShip:
            ch = "X";
            break;
        case Cell::Type::Missed:
            ch = ".";
            break;
    }
    return ch;
}

const char* View::getShipChar(std::shared_ptr<Cell> cell) {
    const char* ch = "1";
    for (const auto &ship: m_ships) {
        std::vector<std::shared_ptr<Cell>> shipPosition = ship->getPosition();
        for (const auto &shipCell: shipPosition) {
            if(shipCell->getRow() == cell->getRow() && shipCell->getColumn() == cell->getColumn()) {
                switch(ship->getType()) {
                    case Ship::Type::fourDeckShip:
                        ch = "4";
                        break;
                    case Ship::Type::threeDeckShip:
                        ch = "3";
                        break;
                    case Ship::Type::doubleDeckShip:
                        ch = "2";
                        break;
                    case Ship::Type::singleDeckShip:
                        ch = "1";
                        break;
                }
            }
        }
    }
    return ch;
}
