#include "TestScene.h"
#include <iostream>

TestScene::TestScene()
{
    
    m_TestRect.x = 20;
    m_TestRect.y = 20;
    m_TestRect.w = 20;
    m_TestRect.h = 20;
}

void TestScene::OnUpdate()
{
    m_TestRect.x +=2;
    m_TestRect.y +=2;
    if(m_TestRect.x >= 920){
        m_TestRect.x = -2;
    }    
    if(m_TestRect.y >= 600){
        m_TestRect.y = -2;
    }
    // std::cout << "x: " << m_TestRect.x << "y: " << m_TestRect.y << std::endl;

}

void TestScene::OnEvent(SDL_Event &event)
{
}

void TestScene::OnRender()
{
    int r=rand()%256,g=rand()%256,b =rand()%256;
    m_Renderer->SetColor(r,g,b,255);
    m_Renderer->FillRect(&m_TestRect);
    // std::cout << "asdfasdf"<< std::endl;

}

std::unordered_map<std::string, int> TestScene::GetDataDict()
{
    return dict;
}

std::vector<SDL_Rect> TestScene::GetObjects()
{
    return std::vector<SDL_Rect>();
}
