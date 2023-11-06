#pragma once

#include <SDL2/SDL.h>

#include <vector>
#include <memory>
#include <unordered_map>

#include "Scene.h"


namespace wd{
    class SceneManager{
        public:
            virtual ~SceneManager(){};
            void OnUpdate();
            void OnRender();
            void OnEvent(SDL_Event& event);
            void AddScene(unsigned short id, std::shared_ptr<Scene> scene);
            void FreeScene(unsigned short id);
            void GoToScene(unsigned short id);
            int GetSceneCounts() const {return m_SceneCounts;}

            void Release();

            static SceneManager* GetInstance();


        private:
            SceneManager();

        private:

            static SceneManager* s_Instance; 
    
            std::unordered_map<unsigned short, std::shared_ptr<Scene>> m_Scenes;
            std::shared_ptr<Scene> m_MainScene;
            unsigned short m_MainSceneID;
            int m_SceneCounts;




    };
}