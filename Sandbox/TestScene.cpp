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
    std::cout << "x: " << m_TestRect.x << "y: " << m_TestRect.y << std::endl;

}

void TestScene::OnEvent(SDL_Event &event)
{
}

void TestScene::OnRender()
{
    
}

void TestScene::GetDataDict()
{
}
