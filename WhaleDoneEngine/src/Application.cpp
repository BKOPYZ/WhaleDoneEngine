#include "../wdpch.h"
#include "base.h"
#include "Application.h"


namespace wd{

    Application* Application::s_Instance = nullptr;

    Application::Application(){
        if(s_Instance != nullptr){
            std::cout << "[WARNING]: Application already exist" << std::endl;
        }
        else{
            s_Instance = this;
            m_IsRunning = true;
            m_Renderer = Renderer::GetInstance();
            m_Timer = Timer::GetInstance();
            m_InputManager = InputManager::GetInstance();

        }
    }

    Application::~Application()
    {
        m_Renderer->Release();
        m_Timer->Release();
        m_InputManager->Release();
    }

    void Application::Run()
    {
        while(m_IsRunning){
            m_Timer->Update();
            OnEvent();
            if(m_Timer->GetDeltaTime() >= (1.0f/FRAMERATE)){

                OnEarlyUpdate();
                OnUpdate();
                OnRender();
                OnLateUpdate();
            }
        }
    }

    void Application::Release()
    {
        delete s_Instance;
        s_Instance = nullptr;
    }

    void Application::Init()
    {
        m_Renderer->Init("GameEngine",900,600,0);
    }

    void Application::OnEarlyUpdate()
    {
        m_InputManager->Update();
    }

    void Application::OnUpdate()
    {
    }

    void Application::OnLateUpdate()
    {
        m_InputManager->UpdatePrevInput();
        m_Timer->Reset();
    }

    void Application::OnEvent()
    {
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                m_IsRunning = false;
                break;
            default:
                break;  
        }
    }

    void Application::OnRender()
    {
        m_Renderer->ClearBackBuffer();
        // scene/layer manager here to do the scene things 
        //TODO: still have to decide which system we gonna use in this engine (layer scene)

        m_Renderer->OnRender(); 
        
    }

}
