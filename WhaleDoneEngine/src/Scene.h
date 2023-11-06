#pragma once

namespace wd{
    class Scene{
        public:
            virtual ~Scene();
            Scene();

            virtual void OnUpdate();
            virtual void OnEvent();
            virtual void OnRender();

        private:
            // maybe we have to add enitiy manager to that can return the obhect to the code then we can modify things here
    };
}