//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_SPRITECLASS_H
#define CITYBUILD_SPRITECLASS_H
#include <SFML/Graphics.hpp>

class SuperSprite{
public:
    SuperSprite(){
        sprite = new sf::Sprite;
        sprite->setColor(sf::Color::Black);
    };
    bool active;
    sf::Sprite *sprite;
    SuperSprite(sf::Sprite* sprite1){
        sprite = sprite1;

    }
    ~SuperSprite(){delete sprite;}

};

class SuperText{
public:
    bool active;
    sf::Text text;
    SuperText(sf::Text text1){
        text = text1;
    }
};
#endif //CITYBUILD_SPRITECLASS_H
