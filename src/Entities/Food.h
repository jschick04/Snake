#pragma once

namespace Snake::Entities
{
    class Food
    {
    public:
        Vector2 position;

        Food();

        void Draw() const;

    private:
        static Vector2 GetRandomPosition();
    };
}
