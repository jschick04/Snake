#include "Game.h"

#include "raymath.h"

namespace Snake
{
    void Game::OnUpdate()
    {
        m_snake.OnUpdate();

        if (IsGameOver())
        {
            Reset();

            return;
        }

        if (!CanEatFood()) { return; }

        m_snake.Eat();
        m_food.Respawn();

        // Ensure we don't respawn where the snake is
        for (unsigned int i = 0; i < m_snake.body.size(); i++)
        {
            if (Vector2Equals(m_snake.body[i], m_food.position))
            {
                m_food.Respawn();

                i = 0;
            }
        }
    }

    void Game::OnRender() const
    {
        m_food.OnRender();
        m_snake.OnRender();
    }

    bool Game::CanEatFood() const
    {
        return Vector2Equals(m_snake.body[0], m_food.position);
    }

    bool Game::IsGameOver() const
    {
        if (m_snake.body[0].x >= CellCount ||
            m_snake.body[0].x < 0 ||
            m_snake.body[0].y >= CellCount ||
            m_snake.body[0].y < 0)
        {
            return true;
        }

        std::deque<Vector2> tempBody = m_snake.body;
        tempBody.pop_front();

        for (unsigned int i = 0; i < tempBody.size(); i++)
        {
            if (Vector2Equals(m_snake.body[0], tempBody[i]))
            {
                return true;
            }
        }

        return false;
    }

    void Game::Reset()
    {
        m_snake.Respawn();
        m_food.Respawn();
    }
}
