#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace wd{
    struct Color{
        short r,g,b,a;
    };
    class Object{
        public:
            Object();
            Object(const std::string& path, float x, float y, float w, float h, float scale, float rotation, Color color);

            virtual void Update();
            virtual void Event();
        // not finish


        private:
            SDL_FRect m_Srect;
            SDL_FRect m_Drect;
            float m_Scale;
            float m_Rotation;
            Color m_Color;
            SDL_Texture* m_Texture;

    };

}