//
// Created by david on 8/18/22.
//
#include "../headers/Game.h"
#include "../headers/Object_Variants/OBJ_House.h"
#include "../headers/UpdateManager.h"
#include "../headers/Texturesheet.h"
#include "../headers/Soundmanager.h"
int Windoww = 1600;
int Windowh = 900;
sf::RenderWindow window(sf::VideoMode(Windoww, Windowh), "City Builder");
sf::Event event;
Texturemanager texturemanager;
UpdateManager updateManager;
Soundmanager soundmanager;
std::shared_ptr<Button> StartButton;
std::shared_ptr<Button> Sound_Button;
std::shared_ptr<House> house2;
Map map();
void Game::init() {
     gamestate = menu_start;

     //house2 = updateManager.get_obj<House>("/home/david/CLionProjects/CityBuild/sprites/GAME/House1.png",sf::Vector2f(100.0,2.0),sf::IntRect(1,1,50,50),texturemanager,updateManager);
     texturemanager.four_types.push_back(Texturemanager::get_sprite("/home/david/CLionProjects/CityBuild/sprites/TEST/GRASS.jpg",sf::IntRect(0,0,50,50)));
     texturemanager.four_types.push_back(Texturemanager::get_sprite("/home/david/CLionProjects/CityBuild/sprites/TEST/ROCK.jpg",sf::IntRect(0,0,50,50)));
     texturemanager.four_types.push_back(Texturemanager::get_sprite("/home/david/CLionProjects/CityBuild/sprites/TEST/SAND.jpg",sf::IntRect(0,0,50,50)));
     texturemanager.four_types.push_back(Texturemanager::get_sprite("/home/david/CLionProjects/CityBuild/sprites/TEST/WATER.jpg",sf::IntRect(0,0,50,50)));
     texturemanager.maps.push_back(&map);
}


void Game::update() {
    updateManager.update_objects();
    check_gamestate();
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

void Game::check_gamestate() {
    if (gamestate == menu_start){
        if(!StartButton){
            soundmanager.play("main");
            StartButton = updateManager.get_text<Button>("Start",sf::Vector2f(1,1),10,texturemanager,updateManager);
            Sound_Button = updateManager.get_text<Button>("Sound",sf::Vector2f(1,150),10,texturemanager,updateManager);

            StartButton->text->active = true;
            Sound_Button->text->active = true;
        }
        if(StartButton->is_clicked(window)){
            gamestate = ingame_on_island;
            StartButton->text->active = false;
            Sound_Button->text->active = false;
            map.active = true;
        }
        if (Sound_Button->is_clicked(window)){
            StartButton->text->active = false;
            Sound_Button->text->active = false;
            gamestate = menu_sound;

        }

    }
    if (gamestate == menu_sound){
    }



}
