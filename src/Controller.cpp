#include "Controller.h"
#include "InputConsoleController.h"
#include "Constants.h"

#include <string>
#include <iostream>

 Controller::Controller(std::shared_ptr<Model> model, 
    std::shared_ptr<IView> view)
    : m_view{view},
      m_model{model}, 
      m_currentPlayer{Controller::Player::player1},
      m_gameOver{false},
      m_state{State::init},
      m_winPlayer{Constants::str_player1}
{
    init();
    changeState(State::playerOneTurn);
}

Controller::~Controller() {

}

void Controller::init() {
    if (auto board1 = getBoard1()) {
        m_view->init(board1->getBoard(), board1->getShips(), 
            board1->getColumns(), board1->getRows());
        m_view->show(board1->getInitBoard());

        m_inputController = 
            std::make_unique<InputConsoleController>(board1->getRows(), board1->getColumns());
    }
}

void Controller::changeState(State state) {
    
    m_state = state;
    switch (state) {
        case State::init:
            init();
            m_state = State::playerOneTurn;
            break;

        case State::playerOneTurn:
        {
            int row, column;
            if(m_inputController) {
                m_inputController->startInput(Constants::str_player1);
                row = m_inputController->getRow();
                column = m_inputController->getColumn();
            }

            if (auto board1 = getBoard1()) {
                board1->attack(row, column);
                m_model->updatedBoardData(board1->getBoard(), board1->getShips(), 
                board1->getColumns(), board1->getRows());

                m_gameOver = board1->isShipsDestroyed();
                
                if (m_gameOver) {
                    m_state = State::GameOver;
                    m_winPlayer = Constants::str_player1;
                    changeState(m_state);
                } else {
                    m_state = State::playerTwoTurn;
                    changePlayer();
                    changeState(m_state);
                } 
            }
        }
            break;

        case State::playerTwoTurn:
        {
            int row, column;
            if(m_inputController) {
                m_inputController->startInput(Constants::str_player2);
                row = m_inputController->getRow();
                column = m_inputController->getColumn();
            }

            if (auto board2 = getBoard2()) {
                board2->attack(row, column);
                m_model->updatedBoardData(board2->getBoard(), board2->getShips(), 
                board2->getColumns(), board2->getRows());

                m_gameOver = board2->isShipsDestroyed();

                if (m_gameOver) {
                    m_state = State::GameOver;
                    m_winPlayer = Constants::str_player2;
                    changeState(m_state);
                } else {
                    m_state = State::playerOneTurn;
                    changePlayer();
                    changeState(m_state);
                } 
            }
        }
            break;

        case State::GameOver:
            std::cout << m_winPlayer << " Win!" << '\n';
            std::cout << "Game Over!" << '\n';
            break;
    
        default:
           break;
    }
}

std::shared_ptr<GameBoard> Controller::getBoard1() const {
  return m_model->getBoard1();
}

std::shared_ptr<GameBoard> Controller::getBoard2() const {
  return m_model->getBoard2();
}

void Controller::changePlayer() {
    if (m_currentPlayer == Controller::Player::player1) {
        m_currentPlayer = Controller::Player::player2;
    } else {
        m_currentPlayer = Controller::Player::player1;
    }
}

bool Controller::checkGameOver() {
    if(auto board = m_model->getBoard1()) {
        if(bool allShipsDestoryed = board->isShipsDestroyed()) {
            gameOver();
            return true;                        
        }
    }
    return false;
}

void Controller::gameOver() {
    std::cout << "Game Over!" << '\n';
}

Position Controller::readInput() {
    return { 0, 0 };
}
