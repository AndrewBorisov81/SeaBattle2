#pragma once
#include "GameBoard.h"
#include "Subject.h"

#include <memory>
class Model {
public:
    Model() = default;
    virtual ~Model() = default;

    bool init(const FieldData& fieldData, const std::vector<ShipData>& shipsData);

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;

    void setSubject(std::shared_ptr<ISubject> subject);
    void updatedBoardData(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
private:
    std::shared_ptr<GameBoard> m_board1;
    std::shared_ptr<GameBoard> m_board2;
    std::shared_ptr<ISubject> m_subject;
};
