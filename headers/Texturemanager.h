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
#include <iostream>
class Texturemanager{
public:

    std::vector<SuperSprite*> Objects;
    std::vector<SuperText*> texts;
    std::vector<Map*> maps;
    std::vector<SuperSprite*> four_types;
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
            if(m->active) {
                SuperSprite *cur_s;
                for (int i = 0; i < m->map_values.size(); i++) {
                    for (int j = 0; j < m->map_values[0].size(); j++) {
                        if (m->map_values[i][j][0] == 0) {
                            cur_s = four_types[0];
                        } else if (m->map_values[i][j][1] == 1) {
                            cur_s = four_types[1];
                        } else if (m->map_values[i][j][2] == 2) {
                            cur_s = four_types[2];
                        } else if (m->map_values[i][j][3] == 3) {
                            cur_s = four_types[3];
                        } else { continue; }
                        cur_s->sprite->setPosition(i * 50, j * 50);
                        window.draw(*cur_s->sprite);
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
