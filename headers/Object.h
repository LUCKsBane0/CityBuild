//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_OBJECT_H
#define CITYBUILD_OBJECT_H
#include <SFML/Graphics.hpp>
#include "./Spriteclass.h"
class Texturemanager;

class Object{
public:
    Object(){}
    sf::Vector2f pos;
    SuperSprite *sprite;
    void pass_the_blunt(std::string path, sf::Vector2f pos_n, sf::IntRect rect, Texturemanager &texturemanager);
    //virtual void draw(){};
    virtual void update(){};
    bool is_active(){
        return sprite->active;
    }
    void set_active(bool x){
        sprite->active = x;
    };
    bool is_clicked();

};





#endif //CITYBUILD_OBJECT_H
