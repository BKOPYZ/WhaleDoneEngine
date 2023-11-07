#include "../wdpch.h"

#include "SceneManager.h"

namespace wd{
    SceneManager* SceneManager::s_Instance = nullptr;
    
    SceneManager::SceneManager(){
        m_MainScene.reset(new Scene());
        m_MainSceneID = -1;
        m_SceneCounts = 0;

    }
    void SceneManager::OnUpdate()
    {
        m_MainScene->OnUpdate();
    }
    void SceneManager::OnRender()
    {
        m_MainScene->OnRender();
    }
    void SceneManager::OnEvent(SDL_Event& event)
    {
        m_MainScene->OnEvent(event);
    }
    void SceneManager::Release()
    {
        delete s_Instance;
        s_Instance = nullptr;
    }
    SceneManager *SceneManager::GetInstance()
    {
        if(s_Instance == nullptr){
            s_Instance = new SceneManager();

        }
        return s_Instance;
    }

    void SceneManager::AddScene(unsigned short id, std::shared_ptr<Scene> scene)
    {
        if(m_Scenes.find(id) != m_Scenes.end()){
            std::cout << "[ERROR]: there is a Scene already exists at ID: " << id << std::endl;
            return;
        }
        m_Scenes[id] = scene;

    }
    void SceneManager::FreeScene(unsigned short id)
    {
        if(m_Scenes.find(id) == m_Scenes.end()){
            std::cout << "[ERROR]: there is no Scene exists at ID: " << id << std::endl;
            return;
        }
        m_Scenes[id].reset();
    }
    void SceneManager::GoToScene(unsigned short id)
    {
        if(m_Scenes.find(id) == m_Scenes.end()){
            std::cout << "[ERROR]: there is no Scene exists at ID: " << id << std::endl;
            return;
        }
        m_MainScene = m_Scenes[id];
        m_MainSceneID = id;
    }
}