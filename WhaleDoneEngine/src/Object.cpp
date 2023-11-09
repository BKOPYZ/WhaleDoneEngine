#include "Object.h"
#include "AssetManager.h"
namespace wd{
    Object::Object()
    {
        Object("",20,20,20,20);
    }
    Object::Object(const std::string & path , float x, float y, float w, float h, float scale, float rotation, Color color, bool isrender)
    {
        m_Texture = path.empty()? nullptr: AssetManager::GetInstance()->GetTexture(path);
        m_Scale = scale ;
        m_ColRect = {x,y,w*scale,h*scale};
        m_Srect = {0,0,w,h};
        m_Drect = {x,y,w*scale, h* scale};
        m_Rotation = rotation;
        m_Color = color;
        m_IsRender = isrender;



    }
}