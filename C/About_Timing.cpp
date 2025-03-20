#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end; 
    std::chrono::duration<float> duration;

    /* data */
    Timer()
    {
        start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;

        std::cout << "Timer took" << ms << " ms " << std::endl;
    }
};


void Function()
{
    Timer timer;

    for(int i = 0; i < 100; i++)
    {
        // std::cout << "Hello" << std::endl;
        std::cout << "Hello\n";
    }
}

int main()
{
    // using namespace std::literals::chrono_literals;
    
    // auto start = std::chrono::steady_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end = std::chrono::steady_clock::now();

    // std::chrono::duration<float> duration = end - start;

    // std::cout << duration.count() << "s " << std::endl;

    Function();

    std::cin.get();
}
