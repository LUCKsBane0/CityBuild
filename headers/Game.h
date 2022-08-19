//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_GAME_H
#define CITYBUILD_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Texturemanager.h"
enum Gamestate{menu1,menu2};

class Game{
public:
    bool is_running = true;
    void init();
    void update();
    void draw();
    void event_handler();
    bool running(){ return is_running;}
    void cleanup();

};

#endif //CITYBUILD_GAME_H
