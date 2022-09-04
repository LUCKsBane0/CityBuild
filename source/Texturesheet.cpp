//
// Created by david on 8/18/22.
//
#include "../headers/Texturesheet.h"



Map::Map(int Field_size_x, int Field_size_y)
{
    size_x = Field_size_x;
    size_y = Field_size_y;
    //std::vector<std::vector<Map_Object>> field;

    field.resize(Field_size_x);
    for (int i = 0; i < Field_size_x; i++)
    {
        field[i].resize(Field_size_y);
        for (int j = 0; j < Field_size_y; j++)
        {
            field[i][j].type = Void;
            field[i][j].tier = 0;

            //draw
            field[i][j].drawx = (i * 50);
            field[i][j].drawy = (j * 50);
        }
    }
    active = true;
}


Map_Object* Map::getPointer(int x, int y)
{
    return &field[x][y];
}

/*
int Map::setStreet(int x, int y)
{

    bool n = false, e = false, s = false, w = false;

    if ((y - 1) >= 0)
    {
        int nx = x, ny = y - 1;

        if(field[nx][ny].type==Street)
        {
            n=true;
        }
    }
    if ((x + 1) <= size_x) {
        int ex = x + 1, ey = y;

        if(field[ex][ey].type==Street)
        {
            e=true;
        }
    }
    if ((y + 1) <= size_y)
    {
        int sx = x, sy = y + 1;

        if(field[sx][sy].type==Street)
        {
            s=true;
        }
    }
    if ((x - 1) >= 0)
    {
        int wx = x+1, wy = y;

        if(field[wx][wy].type==Street)
        {
            w=true;
        }
    }


    //n==false, e==false, s==false, w==false
    if (n==false, e==false, s==false, w==false)
    {
        field[x][y].sprite=???;
    }

}
*/

