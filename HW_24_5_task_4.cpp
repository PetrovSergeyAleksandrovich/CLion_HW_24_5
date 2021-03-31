#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int fieldsize = 10; //set size of battlefield here

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
    int x = 100;
    srand ( time(NULL) );
    x = rand() % fieldsize;
    return x;
}

int randomizer_y()
{
    int y = 100;
    Sleep(1001);
    srand ( time(NULL) );
    y = rand() % fieldsize;
    return y;
}

void move_player(player& player, std::string& user_input)
{
    if(user_input == "w")
    {
        if(player.coordinates.x > 0)
        {
            player.coordinates.x -= 1;
        }
        else return;
    }
    if(user_input == "s")
    {
        if(player.coordinates.x < 9)
        {
            player.coordinates.x += 1;
        }
        else return;
    }
    if(user_input == "a")
    {
        if(player.coordinates.y > 0)
        {
            player.coordinates.y -= 1;
        }
        else return;
    }
    if(user_input == "d")
    {
        if(player.coordinates.y < 9)
        {
            player.coordinates.y += 1;
        }
        else return;
    }
}

void print_battle_field(player& player)
{
    for(int i = 0; i < fieldsize; i++)
    {
        for(int j = 0; j < fieldsize; j++)
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
    std::cout << std::endl;
}



int main()
{
    // init variables
    std::string user_input;
    // initialize gamer and enemy objects on the field;
    int x = randomizer_x();
    int y = randomizer_y();
    srand ( time(NULL) );
    player gamer = {"gamer", 100, 100, 10,
                    {gamer.coordinates.x = x,gamer.coordinates.y = y}};


    while(TRUE)
    {
        print_battle_field(gamer);
        std::cout << ":" << std::endl;
        std::cin >> user_input;
        move_player(gamer, user_input);
    }


    return 0;
}