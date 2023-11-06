#pragma once

#include <vector>
#include <math.h>
#include <iostream>

namespace wd{
    #define PI 3.14159265
    #define DEG_TO_RAD PI/180.0f

    struct Vector2{
        float x,y;
        
        Vector2(float _x = 0.0f, float _y = 0.0f)
			: x(_x), y(_y) {}

        float MagnitudeSqr(){ return x*x + y*y ;}

        float Magnitude(){ return sqrt(MagnitudeSqr());}

        float DotProduct(const Vector2& vec){ return x* vec.x + y* vec.y;}

        bool AbsMorethanEqual(const Vector2& maxVec){
            if(abs(x) >= maxVec.x || abs(y) >= maxVec.y){return true;}
            return false;
        }

        float RadBetweenThisVector2(Vector2& vec){
            float this_mag = Magnitude();
            float vec_mag = vec.Magnitude();
            float dotProd = DotProduct(vec);
            return acos(dotProd/(this_mag * vec_mag));
        };

        Vector2 Normalized(){
            float mag = Magnitude();
            return Vector2(x/mag,y/mag);
        }
        Vector2& operator +=(const Vector2& vec){
            x += vec.x;
            y += vec.y;
            return *this;
        }

        Vector2& operator -=(const Vector2& vec){
            x -= vec.x;
            y -= vec.y;
            return *this;
        }

        Vector2& operator *=(const float& num){
            x *= num;
            y *= num;
            return *this;
        }

        Vector2& operator /=(const float& num){
            x /= num;
            y /= num;
            return *this;
        }
     
    };
    inline Vector2 operator +(const Vector2& lvec, const Vector2& rvec){ 
        return {lvec.x + rvec.x, lvec.y + rvec.y};
    }
    inline Vector2 operator -(const Vector2& lvec, const Vector2& rvec){ 
        return {lvec.x - rvec.x, lvec.y - rvec.y};
    }
    inline Vector2 operator *(const Vector2& lvec, const Vector2& rvec){ 
        return {lvec.x * rvec.x, lvec.y * rvec.y};
    }
    inline Vector2 operator *(const Vector2& lvec, const float& num){ 
        return {lvec.x * num, lvec.y * num};
    }
    inline Vector2 operator /(const Vector2& lvec, const Vector2& rvec){ 
        return {lvec.x / rvec.x, lvec.y / rvec.y};
    }
    const Vector2 VEC_ZERO = {0,0};
    const Vector2 VEC_ONE = {1,1};
    const Vector2 VEC_UP = {0,-1};
    const Vector2 VEC_DOWN = {0,1};
    const Vector2 VEC_LEFT = {-1,0};
    const Vector2 VEC_RIGHT = {1,0};



}