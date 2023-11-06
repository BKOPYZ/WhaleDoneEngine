#include "../wdpch.h"

#include "SceneManager.h"

namespace wd{
    SceneManager* SceneManager::s_Instance = nullptr;

    void SceneManager::OnUpdate()
    {
    }
    void SceneManager::OnRender()
    {
    }
    void SceneManager::OnEvent()
    {
    }
    SceneManager *SceneManager::GetInstance()
    {
        if(s_Instance == nullptr){
            s_Instance = new SceneManager();

        }
        return s_Instance;
    }
    void SceneManager::PushScene(std::shared_ptr<Scene> scene)
    {
        m_Scenes.push(scene);
    }
    std::shared_ptr<Scene> SceneManager::PopScene()
    {
        std::shared_ptr<Scene> temp = m_Scenes.top;
        m_Scenes.pop()
    }
}