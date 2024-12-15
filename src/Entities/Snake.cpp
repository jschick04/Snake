#include "Snake.h"

#include "Game.h"
#include "raymath.h"

namespace Snake::Entities
{
    void Snake::OnUpdate()
    {
        if (IsKeyPressed(KEY_UP) && m_direction.y != 1)
        {
            m_direction = { 0, -1 };
        }
        else if (IsKeyPressed(KEY_DOWN) && m_direction.y != -1)
        {
            m_direction = { 0, 1 };
        }
        else if (IsKeyPressed(KEY_LEFT) && m_direction.x != 1)
        {
            m_direction = { -1, 0 };
        }
        else if (IsKeyPressed(KEY_RIGHT) && m_direction.x != -1)
        {
            m_direction = { 1, 0 };
        }

        if (!CanMove(0.2)) { return; }

        Move();
    }

    void Snake::OnRender() const
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            DrawRectangle(
                static_cast<int>(body[i].x) * Game::CellSize,
                static_cast<int>(body[i].y) * Game::CellSize,
                Game::CellSize,
                Game::CellSize,
                Colors::DarkGreen);
        }
    }

    bool Snake::CanMove(const double interval)
    {
        if (const double currentTime = GetTime(); currentTime - m_lastUpdateTime >= interval)
        {
            m_lastUpdateTime = currentTime;

            return true;
        }

        return false;
    }

    void Snake::Move()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], m_direction));
    }
}
