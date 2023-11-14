#include "CollisionManager.h"

namespace wd{
    std::vector<Object *> CollisionManager::GetObjects(const int &x, const int &y)
    {
        return m_Grid.at(x).at(y);
    }
    void CollisionManager::Update()
    {
        for(int i = 1 ; i < m_MaxY ; i++){
            for( int j = 1 ; j < m_MaxX ; j++ ){
                std::cout << "i: " <<i << " j: " << j << std::endl;

                std::vector<Object*> objects1 = GetObjects(i,j);
                for(auto& object1: objects1){
                    for(int h = -1 ; h < 2 ; h++){
                        for(int v = -1; v < 2 ;v++){
                            std::vector<Object*> objects2 = GetObjects(i + h, j + v);
                            for(auto& object2: objects2){
                                std::cout << "h: " <<h << " v: " << v << std::endl;
                                std::cout << "Object1 Size: " <<objects1.size() << std::endl;
                                std::cout << "Object1 Size: " << objects2.size() << std::endl;
                                CheckCollide(object1,object2);
                            }
                        }

                    }
                }
                
            }
        }
    }
    bool CollisionManager::CheckCollide(Object *obj1, Object *obj2)
    {
        Vector2 pos1 = obj1->GetCenterPos(), pos2 = obj2->GetCenterPos();
        Vector2 dPos12 = pos2- pos1;
        float distance = dPos12.MagnitudeSqr();
        float deltaDistance = (obj1->GetRadius() + obj2->GetRadius() - distance) /2.0f;
        if( distance < obj1->GetRadius() + obj2->GetRadius()){
            float theta = atan(dPos12.y/dPos12.x);
            Vector2 transform = {deltaDistance * cos(theta), deltaDistance * sin(theta)};
            obj2->Transform(transform);
            obj1->Transform(transform * (-1));
            return true;
        }
        return false;


        
    
    }
    void CollisionManager::AddObject(Object *obj)
    {
        Vector2 pos = obj->GetCenterPos();
        int x = floor(pos.x / m_GridSize), y = floor(pos.y / m_GridSize);
        
        m_Grid.at(y).at(x).push_back(obj);
    }
    void CollisionManager::UpdatePos(Object *obj)
    {
        Vector2 pos = obj->GetCenterPos();
        int x = floor(pos.x / m_GridSize), y = floor(pos.y / m_GridSize);
        
        m_Grid.at(y).at(x).push_back(obj);
    }
    
}