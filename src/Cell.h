#pragma once

class Cell {
public:
    enum class Type{ 
        Empty, 
        Ship, 
        DestroyedShip,
        Hit,
        Missed
    };

    Cell();
    Cell(int row, int col);
    virtual ~Cell();

    void setRow(int row);
    int getRow() const;
    void setColumn(int col);
    int getColumn() const;
    bool isEmpty() const;
    void setEmpty(bool empty);
    void setType(Type type);
    Type getType() const;
private:
    int m_row;
    int m_column;
    bool m_isEmpty;
    Type m_type;
};
