//
// Created by david on 8/18/22.
//
#define SET_Grass map_values[i][j][0]=0
#define SET_Rock map_values[i][j][1]=1
#define SET_Sand map_values[i][j][2]=2
#define SET_Water map_values[i][j][3]=3

#define Grass 0
#define Rock 1
#define Sand 2
#define Water 3


#include <iostream>
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

}


Map_Object* Map::getPointer(int x, int y)
{
    return &field[x][y];
}


void Map::wave_function_collapse() {
    srand(time(NULL));
    for (int i = 0; i < map_values.size(); i++) {
        for (int j = 0; j < map_values[0].size(); j++) {
            // if border field
            if ((!i or !j)) {
                SET_Water;
            } else if((i == map_values.size() - 1 or j == map_values[0].size() - 1)){
                if (map_values[i-1][j][Water] == Water or map_values[i][j-1][Water] == Water)
                    SET_Sand;
                else
                    SET_Grass;
            }
        }
    }
    for (int i = 0; i < map_values.size(); i++) {
        for (int j = 0; j < map_values[0].size(); j++) {
            if ((!i or !j) or (i == map_values.size() - 1 or j == map_values[0].size() - 1)) {
                continue;
            }
            if (is_neighbour_to(i, j, Water)) {
                if (rand() % 100 < 45 and !is_neighbour_to(i,j,Grass) and !is_neighbour_to(i,j,Rock)) {
                    SET_Water;
                }  else {
                    SET_Sand;
                }
            } else {
                if (is_neighbour_to(i, j, Sand)) {
                    if (rand() % 100 < 10) {
                        SET_Sand;
                    } else {
                        SET_Grass;
                    }
                } else {
                    if (is_neighbour_to(i,j, Rock)){
                        if(rand()%100 < 45){
                            SET_Rock;
                        } else {
                            SET_Grass;
                        }
                    } else if (is_neighbour_to(i,j,Grass)){
                        if(rand()%100 < 5){
                            SET_Rock;
                        }else{
                            SET_Grass;
                        }
                    }
            }
        }
    }
}
}

    bool Map::is_neighbour_to(int i, int j, int type) {
        if (map_values[i - 1][j][type] == type or map_values[i + 1][j][type] == type or
            map_values[i][j - 1][type] == type or map_values[i][j + 1][type] == type) {
            return true;
        } else {
            return false;
        }
    }

void Map::export_me() {
    std::ofstream output;
    output.open("../Saves/Mapfile.map");
    for (int i = 0; i < map_values.size(); ++i) {
        for (int j = 0; j < map_values[i].size(); ++j) {
            for (int k = 0; k < 3; ++k) {
                output << map_values[i][j][k] << ",";
            }
            output << map_values[i][j][3] << ";";
        } output << "\n";
    }
    output.close();
}

bool Map::import_me() {
    std::ifstream input;
    std::ios_base::iostate exceptionMask = input.exceptions() | std::ios::failbit;
    input.exceptions(exceptionMask);
    try {
        input.open("../Saves/Mapfile.map");
    } catch (std::ios_base::failure& e){
        return false;
    }
    std::string cur_line;
    int column_pointer;
    std::string cur_cell;
    std::stringstream cur_cell_stream;
    std::string cur_value;
    int value_counter = 0;
    for(int i = 0; i < map_values.size(); i++){
        getline(input,cur_line);
        for(int j = 0; j < map_values[0].size(); j++){
            column_pointer = cur_line.find(';');
            cur_cell = cur_line.substr(0, column_pointer);
            cur_cell_stream = std::stringstream(cur_cell);
            cur_line = cur_line.erase(0, column_pointer+1);
            while(getline(cur_cell_stream, cur_value, ',')){
                std::cout<<cur_value<<" ";
                map_values[i][j][value_counter] = std::stoi(cur_value);
                value_counter++;
            }
            value_counter=0;
        }
        std::cout << std::endl;
    }
    return true;
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

