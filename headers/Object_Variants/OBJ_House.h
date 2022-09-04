//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_OBJ_HOUSE_H
#define CITYBUILD_OBJ_HOUSE_H
#include "../Object.h"
#include "../Texturemanager.h"
#include "../UpdateManager.h"
#include <memory>
class House : public Object{
public:
    House(){}
    //void draw() override{}
    void update() override{
        sprite->sprite->setPosition(pos);
    }
    House(std::string path,sf::Vector2f pos_n,sf::IntRect rect,Texturemanager& texturemanager,UpdateManager& updateManager){
        pass_the_blunt(path,pos_n,rect,texturemanager);
    }
};

#endif //CITYBUILD_OBJ_HOUSE_H
