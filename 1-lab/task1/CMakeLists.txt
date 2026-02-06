cmake_minimum_required(VERSION 3.30)
project(task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(sfml)

add_executable(task1
        main.cpp
        Letter/Color.h
        Letter/Letter.h
        Letter/Position.h
        Letter/DrawStrategy/IDrawStrategy.h
        Letter/DrawStrategy/DrawT.h
        Letter/DrawStrategy/DrawE.h
        Letter/DrawStrategy/DrawA.h
        Letter/JumpStrategy/IJumpStrategy.h
        Letter/JumpStrategy/UniformJump.h)

add_custom_command(TARGET task1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:sfml-graphics>"
        $<TARGET_FILE_DIR:task1>
)

add_custom_command(TARGET task1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:sfml-window>"
        $<TARGET_FILE_DIR:task1>
)

add_custom_command(TARGET task1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:sfml-system>"
        $<TARGET_FILE_DIR:task1>
)

target_link_libraries(task1
        sfml-graphics
        sfml-window
        sfml-system
)

# Для Windows добавляем системные библиотеки
if (WIN32)
    target_link_libraries(task1 opengl32 winmm)
endif ()