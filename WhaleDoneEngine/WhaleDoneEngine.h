#pragma once

// ---- this is what user in the sandbox can use
#include "Application.h"
#include "wdpch.h"
#include "Scene.h"
#include <SDL2/SDL.h>
#include "Object.h"

//--entry point

#ifdef MAIN
    #include "EntryPoint.h"
#endif // DEBUG