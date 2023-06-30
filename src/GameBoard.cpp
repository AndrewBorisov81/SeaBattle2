#include "GameBoard.h"

#include <cassert>
#include <iostream>

GameBoard::GameBoard()
    : m_fieldData{}, m_owner{GameBoard::Owner::player1},
      m_inputMode{GameBoard::InputMode::manual},
      m_shipsDestroyed{false}
{
   
}

GameBoard::GameBoard(const FieldData& fieldData,
                     const std::vector<ShipData>& shipData, Owner owner)
    : m_fieldData{fieldData.rows, fieldData.columns},
      m_shipsData{shipData}, 
      m_owner{owner},
      m_shipsDestroyed{false}
{
    setupCells();
    createShips();
    updateBoardData(m_boardInit, true);
     
    // Test 
    //attack
    //ship destroyed
    attack(1, 1);
    attack(2, 1);
    attack(3, 1);
    attack(4, 1);

    attack(3, 3);
    attack(3, 4);
    attack(3, 5);

    attack(7, 1);
    attack(8, 1);
    //missed
    attack(0, 5);
}

GameBoard::~GameBoard() {

}

std::unique_ptr<GameBoard> GameBoard::create(const FieldData& fieldData, 
                                             const std::vector<ShipData>& shipsData, Owner owner) {
    return std::make_unique<GameBoard>(fieldData, shipsData, owner);
}

void GameBoard::deleteBoard() {

}

void GameBoard::clear() {
    m_boardCur.clear();
}

void GameBoard::show() {
 
}

void GameBoard::attack(int row, int col) {
    std::shared_ptr<Cell> initAttackCell = getBoardSpace(row, col, m_boardInit);
    std::shared_ptr<Cell> curAttackCell = getBoardSpace(row, col, m_boardCur);
    if (initAttackCell->getType() == Cell::Type::Ship) {
        if (std::shared_ptr<Ship> attackShip = getShip(row, col)) {
            attackShip->hit(row, col);
        };
    } else if (initAttackCell->getType() == Cell::Type::Empty) {
        curAttackCell->setType(Cell::Type::Missed);
    }

    updateBoardData(m_boardCur);
    
    bool shipsDestroyed{false};
    if(!m_shipsDestroyed) {
        shipsDestroyed = checkShipsDestroyed();
        m_shipsDestroyed = shipsDestroyed; 
    }

    if(m_shipsDestroyed) {
        std::cout << "Game Over!" << '\n';
    }
}

std::shared_ptr<Ship> GameBoard::getShip(int row, int col) {
    if (col >= m_fieldData.columns || col < 0 || row < 0 || row >= m_fieldData.rows) {
            assert(false && "Out of range");
    }
    for (auto &ship: m_ships) {
        CellsList shipPosition = ship->getPosition();
        for (auto &shipCell: shipPosition) {
            if(shipCell->getRow() == row && shipCell->getColumn() == col) {
                return ship;
            }
        }
    }
    return std::shared_ptr<Ship>(nullptr);
}

void GameBoard::setupCells() {
    int numElem = m_fieldData.rows * m_fieldData.columns;
    m_boardCur.reserve(numElem);

    for (int i = 0; i < m_fieldData.rows; i++) {
        for (int j = 0; j  < m_fieldData.columns; j++) {
           std::shared_ptr<Cell> cellCur = std::make_shared<Cell>(i, j);
           m_boardCur.push_back(cellCur);
           std::shared_ptr<Cell> cellInit = std::make_shared<Cell>(i, j);
           m_boardInit.push_back(cellInit);
        }
    }
}

void GameBoard::createShips() {
    for (auto shipData: m_shipsData) {
        const Position shipBeginPoint(shipData.initRow, shipData.initColumn);
        bool isHorizontal = (shipData.direction == 1) ? true : false;
        CellsList resShipPosition;
        getShipPosition(shipBeginPoint, shipData.type, isHorizontal, resShipPosition);
        Ship::Type shipType = static_cast<Ship::Type>(shipData.type);
        m_ships.push_back(Ship::create(shipType, resShipPosition, isHorizontal));
    }
}

const std::shared_ptr<Cell>& GameBoard::getBoardSpace(int row, int col, 
    const CellsList& board) {
    int index = (board.size()/m_fieldData.columns) * row + col; 
    return board.at(index);
}

bool GameBoard::getShipPosition(const Position& pos, 
    int numberDecks, bool horizontal, CellsList& shipPosition) {
    for (int i = 0; i < numberDecks; i++) {
        if (pos.column >= m_fieldData.columns || pos.column < 0 || pos.column + i >= m_fieldData.columns) {
            assert(false && "Out of range");
            return false;
        };
        if (pos.row < 0 || pos.row >= m_fieldData.rows || pos.row + i >= m_fieldData.rows) {
            assert(false && "Out of range");
            return false;
        }
        int curRow = (horizontal) ? pos.row : pos.row + i;
        int curCol = (horizontal) ? pos.column + i : pos.column;
        if (std::shared_ptr<Cell> cell = getBoardSpace(curRow, curCol, m_boardInit)) {
            if (horizontal) {
                cell->setRow(curRow);
                cell->setColumn(curCol);
            } else {
                cell->setRow(curRow);
                cell->setColumn(curCol);
            }
            shipPosition.push_back(cell);
        };
    }
    return true;
}

void GameBoard::updateBoardData(CellsList& board, bool init) {
    for (const auto &ship: m_ships) {
        CellsList shipPosition = ship->getPosition();
        for (const auto &cell: shipPosition) {
            if (auto boardCell = getBoardSpace(cell->getRow(), cell->getColumn(), board)) {
                if(ship->isDestroyed()) {
                    boardCell->setType(Cell::Type::DestroyedShip);
                } else if (ship->isHit() && cell->getType() == Cell::Type::Hit) {
                    boardCell->setType(Cell::Type::Hit);
                } else {
                    if(init) {
                        boardCell->setType(Cell::Type::Ship);
                    }
                }
            }
        }
    }
}

bool GameBoard::checkShipsDestroyed() {
    bool allShipsDestroyed{true};
    for (auto &ship: m_ships) {
        if(!ship->isDestroyed()) {
            return false;
        }
    }
    return allShipsDestroyed;
}

const GameBoard::CellsList& GameBoard::getBoard() const {
    return m_boardCur;
}

const GameBoard::CellsList& GameBoard::getInitBoard() const {
    return  m_boardInit;
}

const GameBoard::ShipsList& GameBoard::getShips() const {
    return m_ships;
}

const FieldData& GameBoard::getFieldData() const {
    return m_fieldData;
}

bool GameBoard::isShipsDestroyed() const {
    return m_shipsDestroyed;
}
