project(WhaleDoneEngine)

set(SANDBOXSOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Sandbox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TestScene.cpp
    )

add_executable(Sandbox Sandbox.cpp)

target_link_libraries(Sandbox Engine ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_include_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../WhaleDoneEngine)