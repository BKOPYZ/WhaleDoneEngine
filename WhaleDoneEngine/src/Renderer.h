#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

namespace wd{
    class Renderer{
        public:
            static Renderer* GetInstance();

            virtual ~Renderer();

            static void Release();

            bool Init(const std::string& title, const int& width, const int& height,const Uint32& flag);
            
            SDL_Texture* CreateTexture(const std::string& path);    

            void DrawTexture(SDL_Texture* texture,SDL_Rect* clipRect = NULL, SDL_Rect* destRect = NULL, const float& angle = 0.0f,SDL_RendererFlip flip = SDL_FLIP_NONE );
            
            void DrawTextureF(SDL_Texture* texture, SDL_Rect* clipRect = NULL, SDL_FRect* destRect = NULL, const float& angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
            
            void SetColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a);

            void FillRect(SDL_Rect* rect);

            void DrawRect(SDL_Rect* rect);

            void DrawLine(const int& x1, const int& y1, const int& x2, const int& y2);

            void ClearBackBuffer();

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