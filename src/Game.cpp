#include "Game.h"

namespace Snake
{
    Game::Game()
    {
        m_food = Entities::Food();
    }

    void Game::OnUpdate() const
    {
        m_food.Draw();
    }
}
