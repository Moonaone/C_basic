#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

char* GetName()
{
    return "Cherno";
}

// auto GetName() -> char*
// {
//     return "Cherno";
// }

class Device
{

};

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Device;

public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevice() const
    {
        return m_Device;
    }
};

int main()
{
    auto a = 5;
    auto b = 10.5f;
    auto c = "Hello World!";

    auto d = GetName();

    // auto e = d.size();

    // µü´úÆ÷
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    // for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    // {
    //     std::cout << (*it) << std::endl;
    // }

    // ¼ò»¯Ð´·¨
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }

    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

    DeviceManager dm;
    // const DeviceMap& device = dm.GetDevice();
    const auto& device = dm.GetDevice();


    std::cin.get();
}
