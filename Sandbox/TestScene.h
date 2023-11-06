#pragma once

#include "WhaleDoneEngine.h"

class TestScene : public wd::Scene{
    public:
        TestScene();
        ~TestScene () override{};
        
        void OnUpdate() override ;
        void OnEvent(SDL_Event& event) override;
        void OnRender() override;
        void GetDataDict() override;

    private:
        SDL_Rect m_TestRect{0,0,0,0};
        


};