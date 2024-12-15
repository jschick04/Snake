#pragma once

namespace Snake::Entities
{
    class Food
    {
    public:
        Vector2 position;

        Food();

        void OnRender() const;

    private:
        static Vector2 GetRandomPosition();
    };
}
