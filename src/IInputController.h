#pragma once
#include <string>

struct Position;
class IInputController {
public:
    virtual void startInput(const std::string& player) = 0;
    virtual void stopInput() = 0;
    virtual int getRow() const = 0;
    virtual int getColumn() const = 0;
    virtual Position readInput() = 0;
    virtual ~IInputController() = default;
};
