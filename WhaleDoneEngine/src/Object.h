#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "Renderer.h"

namespace wd{
    struct Color{
        short r,g,b,a;
    };
    class Object{
        public:
            Object();
            Object(const std::string& path, float x, float y, float w, float h, float scale = 1, float rotation = 0.0f, Color color = {255,255,255,255}, bool isrender = true);

            virtual void Update(){};
            virtual void Event(SDL_Event& event){};
            virtual void Render(){};
        // not finish


        protected:
            bool m_IsRender;
            SDL_FRect m_ColRect;
            SDL_FRect m_Srect;
            SDL_FRect m_Drect;
            float m_Scale;
            float m_Rotation;
            Color m_Color;
            SDL_Texture* m_Texture;

    };

}