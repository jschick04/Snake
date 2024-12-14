#include "Application.h"

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace Snake
{
    Application::Application(const ApplicationSpecification& spec) : m_specification(spec)  // NOLINT(modernize-pass-by-value)
    {
    }

    void Application::OnUpdate()
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    void Application::Run()
    {
        InitWindow(m_specification.Width, m_specification.Height, m_specification.Title.c_str());

#if defined(PLATFORM_WEB)
        emscripten_set_main_loop([this]() { OnUpdate(); }, 0, 1);
#else
        SetTargetFPS(60);

        while (!WindowShouldClose()) // Detect window close button or ESC key
        {
            OnUpdate();
        }
#endif

        CloseWindow();
    }
}
