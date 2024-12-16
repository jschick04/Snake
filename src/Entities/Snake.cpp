#include "Snake.h"

#include "Game.h"
#include "raymath.h"

namespace Snake::Entities
{
    void Snake::Eat()
    {
        body.push_front(Vector2Add(body[0], m_direction));
        m_isEating = true;
    }

    void Snake::Respawn()
    {
        body = { Vector2(6, 9), Vector2(5, 9), Vector2(4, 9) };
        m_direction = { 1, 0 };
        m_canChangeDirection = true;
        m_isEating = false;
        m_isMoving = false;
    }

    void Snake::OnUpdate()
    {
        switch (GetKeyPressed())
        {
            case KEY_UP:
                if (m_direction.y != 1 && m_canChangeDirection)
                {
                    m_direction = { 0, -1 };
                    m_isMoving = true;
                    m_canChangeDirection = false;
                }
                break;
            case KEY_DOWN:
                if (m_direction.y != -1 && m_canChangeDirection)
                {
                    m_direction = { 0, 1 };
                    m_isMoving = true;
                    m_canChangeDirection = false;
                }
                break;
            case KEY_LEFT:
                if (m_direction.x != 1 && m_canChangeDirection)
                {
                    m_direction = { -1, 0 };
                    m_canChangeDirection = false;
                }
                break;
            case KEY_RIGHT:
                if (m_direction.x != -1 && m_canChangeDirection)
                {
                    m_direction = { 1, 0 };
                    m_isMoving = true;
                    m_canChangeDirection = false;
                }
                break;
            default:
                break;
        }

        if (m_isEating)
        {
            m_isEating = false;

            return;
        }

        Move();
    }

    void Snake::OnRender() const
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            DrawRectangle(
                Game::Offset + static_cast<int>(body[i].x) * Game::CellSize,
                Game::Offset + static_cast<int>(body[i].y) * Game::CellSize,
                Game::CellSize,
                Game::CellSize,
                Colors::DarkGreen);
        }
    }

    bool Snake::CanMove(const double interval)
    {
        if (!m_isMoving) { return false; }

        if (const double currentTime = GetTime(); currentTime - m_lastUpdateTime >= interval)
        {
            m_lastUpdateTime = currentTime;
            m_canChangeDirection = true;

            return true;
        }

        return false;
    }

    void Snake::Move()
    {
        if (!CanMove(0.2)) { return; }

        body.pop_back();
        body.push_front(Vector2Add(body[0], m_direction));
    }
}
