#include <iostream>
#include "core/Application.h"
#include "area/AreaManager.h"

int main()
{
    std::cout << "Start Unity AnpanMMO Server..." << std::endl;

    // とりあえずエリア生成
    AreaManager::GetInstance().Make(1);

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
