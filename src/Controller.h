#pragma once
#include "Observer.h"
#include "Model.h"
#include "IView.h"
#include "IInputController.h"

#include <memory>

class Point;

class Controller {
    enum class Player{ player1, player2 };
    enum class State{ init, playerOneTurn, playerTwoTurn, GameOver };
public:
    Controller() = default;
    Controller(std::shared_ptr<Model> model, 
    std::shared_ptr<IView> view);
    virtual ~Controller();
    // when application start
    void init();
    void updateData();

protected:
    std::shared_ptr<IView> m_view;

private:
    std::shared_ptr<Model> m_model;
    std::unique_ptr<IInputController> m_inputController;
    Controller::Player m_currentPlayer;
    bool m_gameOver;
    State m_state;
    std::string m_winPlayer;

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;
    void changeState(State state);
    void changePlayer();
    bool checkGameOver();
    void gameOver();
    Position readInput();
};
