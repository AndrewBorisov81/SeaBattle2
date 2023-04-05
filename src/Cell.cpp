#include "Cell.h"

Cell::Cell() 
    : m_row{0}, m_column{0}, 
      m_isEmpty{true}, m_type{Type::Empty} {

}

Cell::Cell(int row, int col)
    : m_row{row}, m_column{col},
      m_isEmpty{true}, m_type{Type::Empty} {

}

Cell::~Cell() {

}

void Cell::setRow(int row) {
    m_row = row;
}

int Cell::getRow() const {
    return m_row;
}

void Cell::setColumn(int col) {
   m_column = col;
}

int Cell::getColumn() const {
    return m_column;
}

void Cell::setEmpty(bool empty) {
    m_isEmpty = empty;
}

bool Cell::isEmpty() const {
    return m_isEmpty;
}

void Cell::setType(Type type) {
    m_type = type;
    if(m_type != Type::Empty) {
        m_isEmpty = false;
    }
}
    
Cell::Type Cell::getType() const {
    return m_type;
}
