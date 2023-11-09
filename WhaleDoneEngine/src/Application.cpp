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
            // Get instance of the manager after this line
            m_Renderer = Renderer::GetInstance();
            m_Timer = Timer::GetInstance();
            m_InputManager = InputManager::GetInstance();
            m_SceneManager = SceneManager::GetInstance();
            m_AssetManager = AssetManager::GetInstance();
            std::cout << "Initialize success" << std::endl;
        }
    }

    Application::~Application()
    {
        // Release the manager after this line
        m_Renderer->Release();
        m_Timer->Release();
        m_InputManager->Release();
        m_SceneManager->Release();
        m_AssetManager->Release();
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
        m_SceneManager->OnUpdate();
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
        m_SceneManager->OnEvent(event);
    }

    void Application::OnRender()
    {
        m_Renderer->ClearBackBufferWithBackGround(255,255,255,255);
        // scene/layer manager here to do the scene things 
        //TODO: still have to decide which system we gonna use in this engine (layer scene)
        m_SceneManager->OnRender();

        m_Renderer->OnRender(); 
        
    }

}
