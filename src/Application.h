#pragma once

#include <memory>
#include <string>

#include "Game.h"

namespace Snake
{
    struct ApplicationSpecification
    {
        int Height = Game::CellCount * Game::CellSize;
        int Width = Game::CellCount * Game::CellSize;
        std::string Title = "Snake";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());

        void OnUpdate() const;
        void Run();

    private:
        std::unique_ptr<Game> m_game;
        ApplicationSpecification m_specification;
    };
}
