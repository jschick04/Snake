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
        static constexpr int Offset = 75;

        void OnUpdate();
        void OnRender() const;

    private:
        Entities::Food m_food = Entities::Food();
        int m_score = 0;
        Entities::Snake m_snake = Entities::Snake();

        [[nodiscard]] bool CanEatFood() const;
        [[nodiscard]] bool IsGameOver() const;
        void Reset();
    };
}
