#include <iostream>
#include "core/Application.h"

int main()
{
    std::cout << "Start Unity AnpanMMO Server..." << std::endl;

    Application App;
    if (!App.StartListen(1234))
    {
        std::cout << "StartListen Failed." << std::endl;
        return -1;
    }

    while (App.Service())
    {
    }
    return 0;
}
