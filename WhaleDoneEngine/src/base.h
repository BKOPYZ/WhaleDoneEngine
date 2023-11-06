#pragma once
#include <iostream>

#define ASSERT(x) if(!(x)) std::cout << "[ERROR]: " << #x << " " << __FILE__ << ": " << __LINE__ << std::endl;

#define BIT(x) (1 << x)