#define MAIN
#include "WhaleDoneEngine.h"
#include "TestScene.h"

#include <memory>

class Sandbox : public wd::Application{
    public:
        Sandbox(){
            m_SceneManager->AddScene(0,m_TestScene);
            m_SceneManager->GoToScene(0);
        }
        ~Sandbox() override{

        };

    private:
        std::shared_ptr<TestScene> m_TestScene = std::make_shared<TestScene>();
};

wd::Application* wd::CreateApplication(){
    return new Sandbox();
}
