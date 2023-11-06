#pragma once

namespace wd{
    class Timer{
        public:
            static Timer* GetInstance();
            static void Release();
            void Reset();
            inline float GetDeltaTime() const {return m_DeltaTime;}
            void SetTimeScale(float t = 1.0f);
            inline float GetTimeScale() const {return m_TimeScale;} 
            void Update();
            ~Timer(); 
        private:
            Timer();
            static Timer* m_Instance;
            unsigned int m_StartTicks;
            unsigned int m_ElapsedTicks;
            float m_DeltaTime;
            float m_TimeScale;
    };
}