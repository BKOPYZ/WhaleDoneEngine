#include "../wdpch.h"
#include "Renderer.h"
#include "base.h"


namespace wd{
    Renderer* Renderer::s_Instance = nullptr;
    bool Renderer::m_Initailized = false;
    Renderer *Renderer::GetInstance()
    {
        if(s_Instance == nullptr){
            s_Instance = new Renderer();
        }
        return s_Instance;
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(m_Renderer);
        m_Renderer = nullptr;
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }


    bool Renderer::Init(const std::string &title, const int &width, const int &height,const Uint32& flag)
    {
        m_ScreenWidth = width;
        m_ScreenHeight = height;
        //Initialize SDL Video and Audio and handling initialization errors
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

			printf("[ERROR]: SDL Initialization Error: %s\n", SDL_GetError());
			return false;
		}

		//Creating the window
		m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

		//Handling with window creation errors
		if(m_Window == NULL) {

			printf("[ERROR]: Window Creation Error: %s\n", SDL_GetError());
			return false;
		}

		//Creating the renderer
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_SOFTWARE);

		//Handling with the renderer creation errors
		if(m_Renderer == NULL) {

			printf("[ERROR]: Renderer Creation Error: %s\n", SDL_GetError());
			return false;
		}

		//Setting the renderer's clear color to white
        SDL_SetRenderDrawColor(m_Renderer,255,255,255,255);
		
        return true;
    }

    void Renderer::Release()
    {
        delete s_Instance;
        s_Instance = nullptr;

        m_Initailized = false;
    }

    SDL_Texture* Renderer::CreateTexture(const std::string &path)
    {
        SDL_ClearError();
        
        SDL_Surface* tempSurface = IMG_Load(path.c_str());
        std::cout << "1 " << SDL_GetError() << std::endl;
        SDL_ClearError();
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer,tempSurface);
        std::cout << "2 " <<SDL_GetError() << std::endl;

        SDL_FreeSurface(tempSurface);
        return texture;
    }

    void Renderer::DrawTexture(SDL_Texture *texture, SDL_Rect *clipRect, SDL_Rect *destRect, const float &angle, SDL_RendererFlip flip)
    {
        SDL_RenderCopyEx(m_Renderer,texture,clipRect,destRect,angle,NULL,flip);
    }

    void Renderer::DrawTextureF(SDL_Texture *texture, SDL_Rect *clipRect, SDL_FRect *destRect, const float &angle, SDL_RendererFlip flip)
    {
        SDL_RenderCopyExF(m_Renderer,texture,clipRect,destRect,angle,NULL,flip);
    }

    void Renderer::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        SDL_SetRenderDrawColor(m_Renderer, r, g, b,a);
    }

    void Renderer::FillRect(SDL_Rect *rect)
    {
        SDL_RenderFillRect(m_Renderer, rect);
    }

    void Renderer::FillRectF(SDL_FRect *frect)
    {
        SDL_RenderFillRectF(m_Renderer, frect);

    }

    void Renderer::DrawRect(SDL_Rect *rect)
    {
        SDL_RenderDrawRect(m_Renderer,rect);
    }

    void Renderer::DrawRectF(SDL_FRect *frect)
    {
        SDL_RenderDrawRectF(m_Renderer, frect);
    }

    void Renderer::DrawPoint(const int& x,const int&y)
    {
        SDL_RenderDrawPoint(m_Renderer,x,y);
    }

    void Renderer::DrawLine(const int &x1, const int &y1, const int &x2, const int &y2)
    {
        SDL_RenderDrawLine(m_Renderer,x1,y1,x2,y2);
    }

    void Renderer::ClearBackBuffer()
    {
        // tentative

        ClearBackBufferWithBackGround(0,0,0,0);
    }

    void Renderer::ClearBackBufferWithBackGround(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        SDL_SetRenderDrawColor(m_Renderer,r,g,b,a);
        SDL_RenderClear(m_Renderer);
        
    }

    void Renderer::OnRender()
    {  
        SDL_RenderPresent(m_Renderer);
    }
}