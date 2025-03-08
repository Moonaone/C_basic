#include <iostream>

class Log
{
    public:
    const int LoglevelWarning = 1;
    const int LoglevelError = 0;
    const int LoglevelInfo = 2;

    private:
    int m_Loglevel = LoglevelInfo;

    public:
    void SetLevel(int level)
    {
        m_Loglevel = level;
    }

    void Warn(const char* message)
    {
        if(m_Loglevel >= LoglevelWarning)
        {
            std::cout << "[WARNING]:" << message << std::endl;
        }
    }

    void Error(const char* message)
    {
        if(m_Loglevel >= LoglevelError)
        {
            std::cout << "[ERROR]:" << message << std::endl;
        }
    }

    void Info(const char* message)
    {
        if(m_Loglevel >= LoglevelInfo)
        {
            std::cout << "[INFO]:" << message << std::endl;
        }
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LoglevelWarning);
    log.Warn("Hello!");

    std::cin.get();
}
