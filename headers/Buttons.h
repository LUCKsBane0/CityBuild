//
// Created by david on 8/24/22.
//

#ifndef CITYBUILD_BUTTONS_H
#define CITYBUILD_BUTTONS_H
#include "./Spriteclass.h"
#include "./Texturemanager.h"

#include <memory>
class Button{
public:
    sf::Font *font;
    sf::Vector2f pos;
    SuperSprite *sprite;
    SuperText *text;
    sf::FloatRect bbox;
    virtual void update();
    Button(std::string text, sf::Vector2f pos_n, int scale,Texturemanager &texturemanager);
    void pass_the_blunt(std::string Disp, sf::Vector2f pos_n, int scale, Texturemanager &texturemanager);
    bool is_active(){
        return text->active;
    }
    void set_active(bool x){
        text->active = x;
    };
    bool is_clicked(sf::Window& window);
};

#endif //CITYBUILD_BUTTONS_H
