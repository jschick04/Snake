#pragma once

#include <string>

#include "Game.h"

namespace Snake
{
    struct ApplicationSpecification
    {
        int Height = 2 * Game::Offset + Game::CellCount * Game::CellSize;
        int Width = 2 * Game::Offset + Game::CellCount * Game::CellSize;
        std::string Title = "Snake";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());

        void OnUpdate();
        void Run();

    private:
        Game m_game = Game();
        ApplicationSpecification m_specification;
    };
}
