cmake_minimum_required(VERSION 3.23)
project(CityBuild)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML REQUIRED COMPONENTS system window graphics network audio)
add_executable(CityBuild main.cpp
        headers/Texturemanager.h
        source/Texturemanager.cpp
        headers/Texturesheet.h
        source/Texturesheet.cpp
        headers/Game.h
        source/Game.cpp
        headers/Object.h
        source/Object.cpp
        headers/Spriteclass.h
        headers/Object_Variants/OBJ_House.h
        headers/Object_Variants/OBJ_Street.h
        headers/UpdateManager.h
        headers/Buttons.h
        source/Buttons.cpp
        headers/Button_Variants/Start_Button.h
        headers/Soundmanager.h
        source/Soundmanager.cpp)
target_link_libraries (CityBuild sfml-graphics sfml-window sfml-system sfml-network sfml-audio)



#headers/Texturesheet.h source/Texturesheet.cpp
#headers/Object_Variants/OBJ_PICK_MENU.h source/OBJ_PICK_MENU.cpp