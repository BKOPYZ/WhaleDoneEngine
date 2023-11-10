#pragma once

#include <numbers>
#include <math.h>

namespace wd{
    const float PI = std::numbers::pi_v<float>;
    struct Vector2F{
        
        float x, y;

        Vector2F(float x = 0.0f, float y = 0.0f): x(x), y(y){}

        float MagnitudeSq(){
            return x*x + y*y;
        }

        float Magnitude(){
            return sqrt(MagnitudeSq());
        }

        float DotProduct(const Vector2F& vec1){
            return x * vec1.x + y * vec1.y;
        }

        Vector2F& Add(const Vector2F& vec1){
            this->x += vec1.x;
            this->y += vec1.y;
            return *this;
        }


    };





}