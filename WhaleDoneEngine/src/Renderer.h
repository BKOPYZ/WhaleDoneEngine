#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <unordered_map>

namespace wd{
    class Renderer{
        public:
            static Renderer* GetInstance();

            virtual ~Renderer();

            static void Release();

            SDL_Renderer* GetRenderer() const {return m_Renderer;}

            bool Init(const std::string& title, const int& width, const int& height,const Uint32& flag);
            
            SDL_Texture* CreateTexture(const std::string& path); 

            void DrawTexture(SDL_Texture* texture,SDL_Rect* clipRect = NULL, SDL_Rect* destRect = NULL, const float& angle = 0.0f,SDL_RendererFlip flip = SDL_FLIP_NONE );
            
            void DrawTextureF(SDL_Texture* texture, SDL_Rect* clipRect = NULL, SDL_FRect* destRect = NULL, const float& angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
            
            void SetColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a);

            void FillRect(SDL_Rect* rect);
            
            void FillRectF(SDL_FRect* frect);

            void DrawRect(SDL_Rect* rect);

            void DrawRectF(SDL_FRect* frect);

            void DrawPoint(const int& x,const int& y);

            void DrawLine(const int& x1, const int& y1, const int& x2, const int& y2);

            void ClearBackBuffer();

            void ClearBackBufferWithBackGround(Uint8 r,Uint8 g,Uint8 b,Uint8 a);

            void OnRender();

        private:
            
            int m_ScreenWidth;
            int m_ScreenHeight;
            Uint32 m_Flag;
            static bool m_Initailized;

            SDL_Window* m_Window;
            SDL_Renderer* m_Renderer;
            
            static  Renderer* s_Instance;

            Renderer(){}

    
    };
    
}