//
// Created by david on 8/18/22.
//
#include "../headers/Object.h"
#include "../headers/Game.h"
#include "../headers/Texturemanager.h"

void Object::pass_the_blunt(std::string path, sf::Vector2f pos_n, sf::IntRect rect, Texturemanager &texturemanager) {
    sprite = Texturemanager::get_sprite(path,rect);
    texturemanager.Objects.push_back(this->sprite);
    pos = pos_n;
}
