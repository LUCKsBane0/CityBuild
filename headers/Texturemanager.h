//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_TEXTUREMANAGER_H
#define CITYBUILD_TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "./Spriteclass.h"
#include "Object.h"
#include "Texturesheet.h"
class Texturemanager{
public:

    std::vector<SuperSprite*> Objects;
    std::vector<SuperText*> texts;
    std::vector<Map*> maps;
    static SuperSprite* get_sprite(const std::string& path, sf::IntRect rect){

        sf::Texture* texture = new sf::Texture;
        texture->loadFromFile(path, rect);
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(*texture);
        SuperSprite* superSprite = new SuperSprite(sprite);
        return superSprite;
    }

    void drawmaps(sf::RenderWindow& window){
        for(const auto& m : maps){
            if(m->active){
                for (int i = 0; i < m->size_x; ++i) {
                    for (int j = 0; j < m->size_y; ++j) {
                        Map_Object* temp = m->getPointer(i,j);
                        window.draw(*temp->sprite->sprite);
                    }
                }
            }
        }
    }

    void drawsprites(sf::RenderWindow& window){

        for(const auto& o : Objects){
            if(o->active){
                window.draw(*o->sprite);
            }
        }
        for(const auto& t : texts){
            if(t->active){
                window.draw(t->text);
            }
        }
    }
};



#endif //CITYBUILD_TEXTUREMANAGER_H
