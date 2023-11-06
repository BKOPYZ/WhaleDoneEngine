#include "WhaleDoneEngine.h"


class Sandbox : public wd::Application{
    public:
        Sandbox(){

        }
        ~Sandbox() override{

        };

    private:
};

wd::Application* wd::CreateApplication(){
    return new Sandbox();
}
