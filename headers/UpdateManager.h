//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_UPDATEMANAGER_H
#define CITYBUILD_UPDATEMANAGER_H
#include "./Object.h"
#include <vector>
#include <memory>
#include "./Buttons.h"

class UpdateManager{
public:
    template<typename T> std::shared_ptr<T> get_obj(std::string path,sf::Vector2f pos_n,sf::IntRect rect,Texturemanager& texturemanager,UpdateManager& updateManager){

        T * t = new T(path,pos_n,rect,texturemanager,updateManager);
        std::shared_ptr<T> a = std::make_shared<T>(*t);
        updateManager.Objects.emplace_back(a);
        return a;
    }

    template<typename T> std::shared_ptr<T> get_text(std::string text,sf::Vector2f pos_n,int scale,Texturemanager& texturemanager,UpdateManager& updateManager){

        T * t = new T(text, pos_n, scale, texturemanager);
        std::shared_ptr<T> a = std::make_shared<T>(*t);
        updateManager.Buttons.emplace_back(a);
        return a;
    }


    std::vector<std::shared_ptr<Object>> Objects;
    std::vector<std::shared_ptr<Button>> Buttons;
     void update_objects(){

         for(auto & x : Buttons){
             x->update();
         }
         for(auto& x:Objects){
             x->update();

         }
     }

};


#endif //CITYBUILD_UPDATEMANAGER_H
