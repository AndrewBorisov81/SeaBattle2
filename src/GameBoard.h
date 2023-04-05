#pragma once

#include "Cell.h"
#include "Ship.h"
#include "UtilityData.h"

#include <memory>
#include <vector>

class GameBoard {
public:
    using CellsList = std::vector<std::shared_ptr<Cell>>;
    using ShipsList = std::vector<std::shared_ptr<Ship>>;

    enum class Owner{ player, computer, player1, player2 };
    // Input ship position
    enum class InputMode{ manual, autoRandom };

    GameBoard();
    //GameBoard(int rows, int columns);
    GameBoard(const FieldData& fieldData,
              const std::vector<ShipData>& shipData, Owner owner);
    ~GameBoard();

    //static std::unique_ptr<GameBoard> create(int rows, int columns);
    static std::unique_ptr<GameBoard> create(const FieldData& fieldData,
        const std::vector<ShipData>& shipsData, Owner owner);
    // Function for removing the playing and feeling memory
    void deleteBoard();

    void clear();
    void show();

    void setupCells();
    void createShips();
    const std::shared_ptr<Cell>& getBoardSpace(int row, int col,
        const CellsList& board);
    bool getShipPosition(const Position& pos, int numberDecks, bool horizontal,
        CellsList& shipPosition);
    void updateBoardData(CellsList& board, bool init = false);
    std::shared_ptr<Ship> getShip(int row, int col);

    void attack(int row, int col);

    int getWidth() const { return m_fieldData.width; }
    int getHeight() const { return m_fieldData.height; }
    int getColumns() const { return m_fieldData.columns; }
    int getRows() const { return m_fieldData.rows; }

    bool isShipsDestroyed() const;

    const CellsList& getBoard() const;
    const CellsList& getInitBoard() const;
    const ShipsList& getShips() const;
    const FieldData& getFieldData() const;

private:
    FieldData m_fieldData;
    // After init set data
    CellsList m_boardInit;
    // Updated after shoot
    CellsList m_boardCur;
    ShipsList m_ships;
    std::vector<ShipData> m_shipsData;
    Owner m_owner;
    InputMode m_inputMode;
    bool m_shipsDestroyed;

    bool checkShipsDestroyed();
};
