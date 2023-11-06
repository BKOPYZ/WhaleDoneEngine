#pragma once

#include <SDL2/SDL.h>

#include <unordered_map>
#include <string>

// tentative
#include <vector>
#include "Renderer.h"

namespace wd{
    class Scene{
        public:
            virtual ~Scene(){m_Renderer = Renderer::GetInstance();};
            Scene(){};

            virtual void OnUpdate(){};
            virtual void OnEvent(SDL_Event& event){};
            virtual void OnRender(){};
            virtual std::unordered_map<const std::string&, int*> GetDataDict(){};
            virtual std::vector<SDL_Rect> GetObjects(){};

        private:
            Renderer* m_Renderer;

            // maybe we have to add enitiy manager to that can return the obhect to the code then we can modify things here
    };
}