#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "Renderer.h"
#include "mathHelper.h"

namespace wd{
    struct Color{
        short r,g,b,a;
    };
    class Object{
        public:
            Object();
            Object(const std::string& path, float x, float y, float w, float h, float scale = 1, float rotation = 0.0f, Color color = {255,255,255,255}, bool isrender = true);

            Vector2 GetPos() const {return {m_Drect.x,m_Drect.y}; }
            Vector2 GetSize() const {return {m_Drect.w,m_Drect.h};}
            Vector2 GetCenterPos() const {return {m_Drect.x + m_Drect.w/2, m_Drect.y + m_Drect.h/2};}
            Vector2 GetVelecity() const {return m_Velocity;}
            void SetVelocity(const Vector2& vec) {m_Velocity = vec;}
            void Transform(const Vector2& vec) {m_Drect.x + vec.x; m_Drect.y + vec.y;}
            float GetRadius() const {return m_Radius;}
            virtual void Update(){};
            virtual void Event(SDL_Event& event){};
            virtual void Render(){};
        
        // not finish


        protected:
            bool m_IsRender;
            SDL_FRect m_ColRect;
            SDL_FRect m_Srect;
            SDL_FRect m_Drect;
            float m_Radius;
            float m_Scale;
            float m_Rotation;
            Color m_Color;
            SDL_Texture* m_Texture;
            Vector2 m_Velocity;

    };

}