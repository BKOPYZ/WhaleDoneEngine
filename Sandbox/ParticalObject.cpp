#include "ParticalObject.h"

ParticalObject::ParticalObject() : wd::Object()
{
}

ParticalObject::ParticalObject(const std::string &path, float x, float y, float w, float h, float scale, float rotation, wd::Color color, bool isrender) : wd::Object(path, x, y, w, h, scale, rotation, color, isrender)
{
}

void ParticalObject::Update()
{
    if(m_Drect.x > 900 || m_Drect.x < 0){
        m_Velocity.x *= -1;
    }
    if(m_Drect.y > 600 || m_Drect.y < 0){
        m_Velocity.y *= -1;
    }
    m_Drect.x += m_Velocity.x;
    m_Drect.y += m_Velocity.y;
    
}

void ParticalObject::Event(SDL_Event& event)
{
}

void ParticalObject::Render()
{

    Uint8 r = rand()%256 ,b = rand()%256,g = rand()%256,a = 255 ;
    wd::Renderer* temp = wd::Renderer::GetInstance();
    temp->SetColor(r,g,b,a);
    temp->FillRectF(&m_Drect);
}

void ParticalObject::SetVelocity(float x, float y)
{
    m_Velocity.x = x;
    m_Velocity.y = y;
}
