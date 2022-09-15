//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_TEXTURESHEET_H
#define CITYBUILD_TEXTURESHEET_H
#include "./Spriteclass.h"
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
enum type{Void, Street, Hotel, Shop, Airport};

struct Map_Object
{
    enum type type;
    int tier;
    int drawx;
    int drawy;
    //Might want to change sprite to object shared ptr for easier use overall
    SuperSprite* sprite = nullptr;
    ~Map_Object(){
        delete sprite;
    }
};


class Map{
public:
    std::vector<std::vector<Map_Object>> field;
    bool is_neighbour_to(int i, int j,int type);
    int size_x;
    int size_y;
    Map(int Field_size_x, int Field_size_y);
    Map_Object* getPointer(int x, int y);
    //int setStreet(int x, int y);

    bool active = false;
    void export_me();
    bool import_me();
};


#endif //CITYBUILD_TEXTURESHEET_H
