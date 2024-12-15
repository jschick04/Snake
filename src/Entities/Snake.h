#pragma once

#include <deque>

namespace Snake::Entities
{
    class Snake
    {
    public:
        std::deque<Vector2> body = { Vector2(6, 9), Vector2(5, 9), Vector2(4, 9) };

        void OnUpdate();
        void OnRender() const;

    private:
        Vector2 m_direction = Vector2(1, 0);
        double m_lastUpdateTime = 0;

        bool CanMove(double interval);
        void Move();
    };
}
