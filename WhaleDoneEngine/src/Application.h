#pragma once
#include "Renderer.h"
#include "Timer.h"
#include "InputManager.h"

namespace wd{
    class Application{
        public:
            Application();
            virtual ~Application();
            void Run();
            void Release();
            void Init();
            

        private: 
            virtual void OnEarlyUpdate();
            virtual void OnUpdate();
            virtual void OnLateUpdate();
            virtual void OnEvent();
            virtual void OnRender();

        private:
            static Application* s_Instance;
            const int FRAMERATE = 120;
            bool m_IsRunning;

            Renderer* m_Renderer;
            Timer* m_Timer;
            InputManager* m_InputManager;

            SDL_Event event;
            


            

    };
    Application* CreateApplication();
}