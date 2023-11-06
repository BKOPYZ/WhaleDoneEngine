#pragma once

#include <vector>
#include <memory>
#include <stack>

#include "Scene.h"

namespace wd{
    class SceneManager{
        public:
            virtual ~SceneManager(){};
            void OnUpdate();
            void OnRender();
            void OnEvent();

            static SceneManager* GetInstance();
            
            void PushScene(std::shared_ptr<Scene> scene);
            std::shared_ptr<Scene> PopScene();


        private:
            SceneManager();

        private:
            static SceneManager* s_Instance; 
            std::stack<std::shared_ptr<Scene>> m_Scenes;




    };
}