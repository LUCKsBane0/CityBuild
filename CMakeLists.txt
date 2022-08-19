cmake_minimum_required(VERSION 3.23)
project(CityBuild)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML REQUIRED COMPONENTS system window graphics network audio)
add_executable(CityBuild main.cpp headers/Texturemanager.h source/Texturemanager.cpp headers/Texturesheet.h source/Texturesheet.cpp headers/Game.h source/Game.cpp  headers/Object.h source/Object.cpp headers/Spriteclass.h headers/OBJ_House.h headers/OBJ_Street.h  headers/UpdateManager.h)
target_link_libraries (CityBuild sfml-graphics sfml-window sfml-system sfml-network)



#headers/Texturesheet.h source/Texturesheet.cpp