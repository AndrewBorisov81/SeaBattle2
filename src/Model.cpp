#include "Model.h"

#include <cassert>

bool Model::init(const FieldData& fieldData, const std::vector<ShipData>& shipsData) {
    m_board1 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player1);
    m_board2 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player2);
    return true;
}

std::shared_ptr<GameBoard> Model::getBoard1() const {
    return m_board1;
}

std::shared_ptr<GameBoard> Model::getBoard2() const {
    return m_board2;
}

void Model::setSubject(std::shared_ptr<ISubject> subject) {
    m_subject = subject;
}

void Model::updatedBoardData(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) 
{
    if(m_subject) {
        m_subject->notify(board, ships, rows, columns);
    } else {
        assert(false && "Subject nullptr");
    }
}

