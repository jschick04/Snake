#pragma once
#include <string>

namespace Snake
{
    struct ApplicationSpecification
    {
        int Width = 800;
        int Height = 450;
        std::string Title = "Snake";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());

        void OnUpdate();
        void Run();

    private:
        ApplicationSpecification m_specification;
    };
}
