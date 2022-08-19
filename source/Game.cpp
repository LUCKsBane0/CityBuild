//
// Created by david on 8/18/22.
//
#include "../headers/Game.h"
#include "../headers/OBJ_House.h"
#include "../headers/UpdateManager.h"
#include "../headers/Texturesheet.h"
sf::RenderWindow window(sf::VideoMode(1600, 900), "City Builder");
sf::Event event;
Texturemanager texturemanager;
UpdateManager updateManager;
Map map();
void Game::init() {
    std::shared_ptr<House> house2 = updateManager.get_obj<House>("/home/david/CLionProjects/CityBuild/sprites/GAME/House1.png",sf::Vector2f(100.0,2.0),sf::IntRect(1,1,50,50),texturemanager,updateManager);
}


void Game::update() {
    updateManager.update_objects();
}

void Game::draw() {
    window.clear(sf::Color::Black);
    texturemanager.drawmaps(window);
    texturemanager.drawsprites(window);
    window.display();
}

void Game::event_handler() {
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            is_running = false;
    }
}

void Game::cleanup() {


}
