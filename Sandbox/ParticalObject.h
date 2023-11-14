#pragma once
#include "WhaleDoneEngine.h"


class ParticalObject : public wd::Object
{
public:
    ParticalObject();

    ParticalObject(const std::string& path, float x, float y, float w, float h, float scale = 1, float rotation = 0.0f, wd::Color color = {255,255,255,255}, bool isrender = true) ;

    void Update() override;
    
    void Event(SDL_Event& event) override;

    void Render() override;

    void SetVelocity(float x, float y);



private:
    


    /* data */
    
};


