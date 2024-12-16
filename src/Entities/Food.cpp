#include "Food.h"
#include "Game.h"

namespace Snake::Entities
{
    Food::Food()
    {
        position = GetRandomPosition();
    }

    void Food::Respawn()
    {
        position = GetRandomPosition();
    }

    void Food::OnRender() const
    {
        DrawRectangle(
            static_cast<int>(position.x) * Game::CellSize,
            static_cast<int>(position.y) * Game::CellSize,
            Game::CellSize,
            Game::CellSize,
            Colors::DarkGreen);
    }

    Vector2 Food::GetRandomPosition()
    {
        const float x = static_cast<float>(GetRandomValue(0, Game::CellCount - 1));
        const float y = static_cast<float>(GetRandomValue(0, Game::CellCount - 1));

        return Vector2 { x, y };
    }
}
