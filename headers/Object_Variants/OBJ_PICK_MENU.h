//
// Created by david on 9/14/22.
//

#include "../Object.h"
#include "../Buttons.h"
#include "../UpdateManager.h" // wichtig
#include "../Texturemanager.h" // wichtig
#ifndef CITYBUILD_OBJ_PICK_MENU_H
#define CITYBUILD_OBJ_PICK_MENU_H

#endif //CITYBUILD_OBJ_PICK_MENU_H

class Menu : public Object{
public:
    Menu(UpdateManager& updateManager,Texturemanager& texturemanager,sf::RenderWindow window){
        open_button = updateManager.get_text<Button>("Menu",sf::Vector2f(1,1),10,texturemanager,updateManager);
        open_button->is_clicked(window);

    }
    std::shared_ptr<Button> open_button;



    //void draw() override{}
    void update() override{
        open_button->update();
    }

};