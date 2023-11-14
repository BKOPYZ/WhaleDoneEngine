#include <vector>
#include "Object.h"

namespace wd{
    class CollisionManager{
        public:
            CollisionManager(int gridsize,int screenwidth, int screenheight):m_GridSize(gridsize), m_MaxX(screenwidth/gridsize),m_MaxY(screenheight/gridsize){
                std::vector<std::vector<std::vector<Object*>>>temp(m_MaxY+1, std::vector<std::vector<Object*>> (m_MaxX+1));
                m_Grid = temp;
            }
            ~CollisionManager(){}

            std::vector<Object*> GetObjects(const int& x, const int& y);
            void Update();
            bool CheckCollide(Object* obj1, Object* obj2);
            void AddObject(Object* obj);
            void UpdatePos(Object* obj);
            void Clear();
        private:
            int m_GridSize;
            int m_MaxY;
            int m_MaxX;
            std::vector<std::vector<std::vector<Object*>>> m_Grid;
    };
    
}