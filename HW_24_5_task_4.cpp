#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

struct vec_2d
{
    int x;
    int y;
};

struct enemy
{
    std::string name = "noname";
    int HP = 0;
    int AP = 0;
    int damage = 0;
    vec_2d coordinates = {0,0};
};

struct player
{
    std::string name = "noname";
    int HP = 0;
    int AP = 0;
    int damage = 0;
    vec_2d coordinates = {0,0};
};

int randomizer_x()
{
    int x = 0;
    srand ( time(NULL) );
    x = rand() % 10;
    return x;
}

int randomizer_y()
{
    int y = 0;
    srand ( time(NULL) );
    y = rand() % 10;
    return y;
}

void print_battle_field(player& player)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if( i == player.coordinates.x && j == player.coordinates.y)
            {
                std::cout << "P" << " ";
            }
            else
            {
                std::cout << "." << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    // initialize gamer and enemy objects on the field;
    int x = randomizer_x();
    int y = randomizer_y();
    srand ( time(NULL) );
    player gamer = {"gamer", 100, 100, 10,
                    {gamer.coordinates.x = x,gamer.coordinates.y = x}};

    print_battle_field(gamer);


    return 0;
}