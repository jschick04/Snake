#pragma once

#include "Entities/Food.h"

namespace Snake
{
    class Game
    {
    public:
        static constexpr int CellCount = 25;
        static constexpr int CellSize = 30;

        Game();

        void OnUpdate() const;

    private:
        Entities::Food m_food;
    };
}
