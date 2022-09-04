//
// Created by david on 8/24/22.
//
#include "../headers/Buttons.h"
#include "../headers/Texturemanager.h"
void Button::pass_the_blunt(std::string Disp, sf::Vector2f pos_n,int scale, Texturemanager &texturemanager) {
    sf::Text temptext;

    font = new sf::Font;
    font->loadFromFile("../Fonts/FreeSans.ttf");
    temptext.setFont(*font);
    temptext.setCharacterSize(60);
    temptext.setFillColor(sf::Color::White);
    temptext.setPosition(pos_n);
    temptext.setScale(2,2);
    temptext.setString(Disp);
    SuperText* tempsuper = new SuperText(temptext);
    texturemanager.texts.push_back(tempsuper);

}

bool Button::is_clicked(sf::Window window) {
    bbox = text->text.getGlobalBounds();
    sf::Vector2f mouse(sf::Mouse::getPosition(window));
    if ( bbox.contains(mouse)){
        return true;
    }
    return false;
}

Button::Button(std::string text, sf::Vector2f pos_n, int scale,Texturemanager &texturemanager) {
    pass_the_blunt(text,pos_n,scale,texturemanager);
}

void Button::update() {

}

