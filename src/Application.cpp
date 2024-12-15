#include "Application.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace Snake
{
    Application::Application(const ApplicationSpecification& spec) : m_specification(spec) { }

    void Application::OnUpdate() const
    {
        BeginDrawing();

        ClearBackground(Colors::Green);

        m_game->OnUpdate();
        m_game->OnRender();

        EndDrawing();
    }

    void Application::Run()
    {
        InitWindow(m_specification.Width, m_specification.Height, m_specification.Title.c_str());

#if defined(PLATFORM_WEB)
        emscripten_set_main_loop([this]() { OnUpdate(); }, 0, 1);
#else
        SetTargetFPS(60);

        m_game = std::make_unique<Game>();

        while (!WindowShouldClose()) // Detect window close button or ESC key
        {
            OnUpdate();
        }
#endif

        CloseWindow();
    }
}
