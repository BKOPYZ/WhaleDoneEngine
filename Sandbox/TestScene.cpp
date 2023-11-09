#include "TestScene.h"
#include <iostream>

TestScene::TestScene()
{
    
    // m_TestRect.x = 20;
    // m_TestRect.y = 20;
    // m_TestRect.w = 20;
    // m_TestRect.h = 20;
    for(int i =0 ; i < 100 ; i++){
        float x = rand()%900, y = rand()%600, w = rand()%25;
        ParticalObject* temp = new ParticalObject("",x,y,w,w);
        float vx = rand()%15 / 10.0 * pow(-1,(rand()%2)),vy = rand()%15 /10.0* pow(-1,(rand()%2));
        temp->SetVelocity(vx,vy);
        m_Objects.emplace_back(temp);
    }
    

}

void TestScene::OnUpdate()
{
    // m_TestRect.x +=2;
    // m_TestRect.y +=2;
    // if(m_TestRect.x >= 920){
    //     m_TestRect.x = -2;
    // }    
    // if(m_TestRect.y >= 600){
    //     m_TestRect.y = -2;
    // }
    // std::cout << "x: " << m_TestRect.x << "y: " << m_TestRect.y << std::endl;
    for(unsigned int i = 0; i< m_Objects.size() ; ++i ){
        m_Objects[i]->Update();
    }

}

void TestScene::OnEvent(SDL_Event &event)
{
}

void TestScene::OnRender()
{
    // int r=rand()%256,g=rand()%256,b =rand()%256;
    // m_Renderer->SetColor(r,g,b,255);
    // m_Renderer->FillRect(&m_TestRect);
    // std::cout << "asdfasdf"<< std::endl;
    for(unsigned int i = 0; i< m_Objects.size() ; ++i ){
        m_Objects[i]->Render();
    }

}

std::unordered_map<std::string, int> TestScene::GetDataDict()
{
    return dict;
}

std::vector<SDL_Rect> TestScene::GetObjects()
{
    return std::vector<SDL_Rect>();
}
