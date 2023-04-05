#pragma once
#include "ILogger.h"

class ShipsLogger: public ILogger {
public:
    ShipsLogger() = default;
    virtual ~ShipsLogger() = default;
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships);
};
