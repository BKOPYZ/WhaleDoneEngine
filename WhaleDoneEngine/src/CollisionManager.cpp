#include "CollisionManager.h"

namespace wd{
    std::vector<Object *> CollisionManager::GetObjects(const int &x, const int &y)
    {
        return m_Grid[x][y];
    }
    void CollisionManager::Update()
    {
        for(int i = 1 ; i < m_MaxY-1; i++){
            for( int j = 1 ; j < m_MaxX-1 ; j++ ){
                std::vector<Object*> objects1 = GetObjects(i,j);
                for(int h = -1 ; h <=1 ; h++){
                    for(int v = -1; v <=1 ;v++){
                        std::vector<Object*> objects2 = GetObjects(i + h, j + v);
                        for(auto& object1: objects1){
                            for(auto& object2: objects2){
                                if (object1 != object2){
                                    CheckCollide(object1,object2);

                                }
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
            // std::cout << "transform x: " << transform.x << " y: " << transform.y << std::endl;
            obj2->Transform(transform);
            obj1->Transform(transform * (-1));
            // Vector2 velo1 = obj1->GetVelecity();
            // Vector2 velo2 = obj2->GetVelecity();
            // float alpha1 = atan(velo1.y/velo1.x);
            // float alpha2 = atan(velo2.y/velo2.x);
            
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

    void CollisionManager::Clear()
    {
        for(auto& vecs: m_Grid){
            for(auto& vec1: vecs){
                vec1.clear();
            }
        }
    }
}