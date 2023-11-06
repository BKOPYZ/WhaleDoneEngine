#pragma once 
#include "Renderer.h"
#include <unordered_map>

namespace wd{
    class AssetManager{
        public:
        static AssetManager* GetInstance();
        
        ~AssetManager();

        void Release();

        SDL_Texture* GetTexture(const std::string& name);

        private:
        AssetManager();
        
        static AssetManager* m_Instance;
        std::string m_Path;
        std::unordered_map<std::string, SDL_Texture*> m_TextureMap;


    };
}