//
// Created by david on 9/14/22.
//

#ifndef CITYBUILD_SOUNDMANAGER_H
#define CITYBUILD_SOUNDMANAGER_H
#include <SFML/Audio.hpp>
#include <iostream>
class Soundmanager{
    sf::Music main_song;
public:
    Soundmanager(){
        if(!main_song.openFromFile("../Sounds/Music/Example.ogg")){
            std::cout << "ERROR" << "\n";
        }

    }
    void play(const std::string& song){
        if(song == std::string ("main")){
            main_song.play();
        }
    }
};

#endif //CITYBUILD_SOUNDMANAGER_H
