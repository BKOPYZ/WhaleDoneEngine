#pragma once
#include "Application.h"
#include <iostream>

extern wd::Application* wd::CreateApplication();

int main(int argc ,char** argv){
    wd::Application* application = wd::CreateApplication();
    application->Init();
    application->Run();
    application->Release();

    application = nullptr;
    std::cout<< "System Exits" << std::endl;
    return 0;
    
}
    




