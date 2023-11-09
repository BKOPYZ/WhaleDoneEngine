#pragma once

#include "WhaleDoneEngine.h"
#include <unordered_map>
#include <vector>
#include <string>

#include "ParticalObject.h"


class TestScene : public wd::Scene{
    public:
        TestScene();
        ~TestScene () override{};
        
        void OnUpdate() override ;
        void OnEvent(SDL_Event& event) override;
        void OnRender() override;
        std::unordered_map<std::string,int> GetDataDict() override;
        std::vector<SDL_Rect> GetObjects() override;

    private:
        // SDL_Rect m_TestRect{0,0,0,0};
        std::unordered_map<std::string, int> dict;
        std::vector<ParticalObject*> m_Objects;
        


};