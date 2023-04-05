#include "InputConsoleController.h"
#include "UtilityData.h"

#include <iostream>
#include <string>
#include <queue>

#include <sstream>
#include <limits>
#include <algorithm>
#include <cctype>

InputConsoleController::InputConsoleController()
    : m_rows{-1}, m_columns{-1}, m_startInput{false}
{
  
}

InputConsoleController::InputConsoleController(int rows, int columns)
    : m_rows{rows}, m_columns{columns}, m_startInput{false}
{
  
}

void InputConsoleController::startInput(const std::string& player) {
   m_startInput = true;
   int row{}, column{};

   std::cout << player << " choose a row. ";
   row = InputConsoleController::getInputNumber();

   std::cout << player << " choose a column. ";
   column = InputConsoleController::getInputNumber();
   
   m_inputRow = row;
   m_inputColumn = column;

   m_startInput = false;
}

void InputConsoleController::stopInput() {
    m_startInput = false;
}

int InputConsoleController::getRow() const {
    return m_inputRow;
}

int InputConsoleController::getColumn() const {
    return m_inputColumn;
}

int InputConsoleController::getInputNumber() {
    int number;
    std::string input;

    while (true) {
        std::cout << "Enter a number from 0 to 11: ";
        std::getline(std::cin, input);
        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

        if (input.empty() || !(std::stringstream(input) >> number) || number < 0 || number > 11) {
            std::cout << "Invalid input. Please enter an integer between 0 and 11." << std::endl;
        } else {
            break;
        }
    }

    std::cout << "The number you entered is: " << number << std::endl;
    
    return number;
}

Position InputConsoleController::readInput() {
    return { m_inputRow, m_inputColumn };
}
