#pragma once

#include "Entities/Food.h"
#include "Entities/Snake.h"

namespace Snake
{
    class Game
    {
    public:
        static constexpr int CellCount = 25;
        static constexpr int CellSize = 30;

        void OnUpdate();
        void OnRender() const;

    private:
        Entities::Food m_food = Entities::Food();
        Entities::Snake m_snake = Entities::Snake();

        [[nodiscard]] bool CanEatFood() const;
        [[nodiscard]] bool IsGameOver() const;
        void Reset();
    };
}
