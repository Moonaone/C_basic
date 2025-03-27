#include <iostream>

struct Vector2
{
    /* data */
    float x, y;
};

struct Vector4
{
    union 
    {
        /* data */
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 a, b;
        };
    };


    Vector2 GetA()
    {
        return Vector2();
    }
};

void PrintVector2(const Vector2& vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    struct Union
    {
        /* data */
        union 
        {
            /* data */
            float a;
            int b;
        };
    };
    
    Union u;
    u.a = 2.0f;
    std::cout << u.a << ", " << u.b << std::endl;

    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    vector.x = 2.0f;
    PrintVector2(vector.a);
    vector.z = 500.f;
    std::cout << "-----------" << std::endl;
    PrintVector2(vector.a);
    PrintVector2(vector.b);

    std::cin.get();
}
