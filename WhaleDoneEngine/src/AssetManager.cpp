#include "../wdpch.h"
#include "AssetManager.h"
namespace wd{
    AssetManager* AssetManager::m_Instance = nullptr;

    AssetManager *AssetManager::GetInstance()
    {
        if(m_Instance == nullptr){
            m_Instance = new AssetManager();
        }
        return m_Instance;
    }

    AssetManager::~AssetManager()
    {
        for(auto texture: m_TextureMap){
            if(texture.second != nullptr){
                SDL_DestroyTexture(texture.second);
            }
        }
    }

    void AssetManager::Release()
    {
        delete m_Instance;
        m_Instance = nullptr;
    }

    SDL_Texture *AssetManager::GetTexture(const std::string& name)
    {
        std::string fullpath = m_Path + "/assets/png/" + name;
        std::cout << fullpath <<std::endl;
        if(m_TextureMap[fullpath] == nullptr){
            m_TextureMap[fullpath] = Renderer::GetInstance()->CreateTexture(fullpath);
        }
        return m_TextureMap[fullpath];
    }

    AssetManager::AssetManager()
    {
        m_Path = SDL_GetBasePath();
        m_Path = m_Path.substr(0,m_Path.find_last_of('/'));
        m_Path = m_Path.substr(0,m_Path.find_last_of('/'));
        m_Path = m_Path.substr(0,m_Path.find_last_of('/'));
    }
}