#include "Game.h"

namespace Snake
{
    void Game::OnUpdate()
    {
        m_snake.OnUpdate();
    }

    void Game::OnRender() const
    {
        m_food.OnRender();
        m_snake.OnRender();
    }
}
