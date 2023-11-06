#include "../wdpch.h"
#include "Timer.h"
#include <SDL2/SDL.h>

namespace wd{
    Timer* Timer::m_Instance = nullptr;

    Timer* Timer::GetInstance(){
        if(m_Instance == nullptr){
            m_Instance = new Timer();
        }
        return m_Instance;
    }

    void Timer::Release(){
        delete m_Instance;
        m_Instance = nullptr;
    }
    
    Timer::Timer(){
        Reset();
        m_TimeScale = 1.0f;
    }
    void Timer::Update()
    {
        m_ElapsedTicks = SDL_GetTicks() - m_StartTicks;
        m_DeltaTime = m_ElapsedTicks * 0.001f;
    }
    Timer::~Timer()
    {
    }

    void Timer::Reset(){
        m_StartTicks = SDL_GetTicks();
        m_ElapsedTicks = 0;
        m_DeltaTime = 0.0f;
    }

    void Timer::SetTimeScale(float t)
    {
        m_TimeScale = t;
    }
}