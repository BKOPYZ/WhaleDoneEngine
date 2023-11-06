// might not have to use this class


#pragma once

#include "Timer.h"
#include "EventManager.h"
#include "Renderer.h"

namespace wd{
    class Window{
        public:
            virtual ~Window();
            void Init();
            void Release();
        private:
            static Window* s_Instance; 


    };
}