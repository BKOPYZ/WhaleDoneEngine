project(WhaleDoneEngine)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(ENGINESOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AssetManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/InputManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SceneManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/wdpch.h)

add_library(Engine STATIC ${ENGINESOURCE})



target_link_libraries(Engine ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
                                            ${SDL2_INCLUDE_DIRS}
                                            ${SDL2IMAGE_INCLUDE_DIRS})
target_precompile_headers(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/wdpch.h)