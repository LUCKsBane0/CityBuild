//
// Created by david on 8/18/22.
//

#ifndef CITYBUILD_TEXTURESHEET_H
#define CITYBUILD_TEXTURESHEET_H
#include "./Spriteclass.h"
#include <vector>
enum type{Void, Street, Hotel, Shop, Airport};

struct Map_Object
{
    enum type type;
    int tier;
    int drawx;
    int drawy;
    SuperSprite* sprite = nullptr;
    ~Map_Object(){
        delete sprite;
    }
};


class Map{
public:
    std::vector<std::vector<Map_Object>> field;

    int size_x;
    int size_y;
    Map(int Field_size_x, int Field_size_y);
    Map_Object* getPointer(int x, int y);
    int setStreet(int x, int y);

    bool active = false;
};


#endif //CITYBUILD_TEXTURESHEET_H
