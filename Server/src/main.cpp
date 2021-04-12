#include <iostream>
#include "core/Application.h"
#include "timer/TickManager.h"
#include "area/AreaManager.h"
#include <unistd.h>

int main()
{
    std::cout << "Start Unity AnpanMMO Server..." << std::endl;

    // とりあえずエリア生成
    AreaManager::GetInstance().Make(1);
    TickManager::GetInstance().Add(std::bind(&AreaManager::Poll, &AreaManager::GetInstance(), std::placeholders::_1));

    Application App;
    if (!App.StartListen(1234))
    {
        std::cout << "StartListen Failed." << std::endl;
        return -1;
    }

    while (App.Service())
    {
        TickManager::GetInstance().Poll();
        usleep(30000);
    }
    return 0;
}
