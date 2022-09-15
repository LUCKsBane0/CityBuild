#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "./headers/Game.h"

Game game;



int main() {
    game.init();
    while(game.running()){
        game.event_handler();
        game.update();
        game.draw();
    }



    return 0;

}
