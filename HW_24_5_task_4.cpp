#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int fieldsize =  10; //set size of battlefield here
int enemy_quantity = 2; // set enemies on the field here

struct vec_2d
{
    int x;
    int y;
};

struct enemy
{
    int name = 0;
    int HP = 0;
    int AP = 0;
    int damage = 0;
    vec_2d coordinates = {0,0};
};

struct enemies_list
{
    std::vector<enemy> list = {};
};

struct player
{
    std::string name = "noname";
    int HP = 0;
    int AP = 0;
    int damage = 0;
    vec_2d coordinates = {0,0};
};

int randomizer()
{
    int x = 100;
    Sleep(1001);
    srand ( time(NULL) );
    x = rand() % fieldsize;
    return x;
}

void move_player(player& player, std::string& user_input)
{
    if(user_input == "w")
    {
        if(player.coordinates.y > 0)
        {
            player.coordinates.y -= 1;
        }
        else return;
    }
    if(user_input == "s")
    {
        if(player.coordinates.y < fieldsize - 1)
        {
            player.coordinates.y += 1;
        }
        else return;
    }
    if(user_input == "a")
    {
        if(player.coordinates.x > 0)
        {
            player.coordinates.x -= 1;
        }
        else return;
    }
    if(user_input == "d")
    {
        if(player.coordinates.x < fieldsize - 1)
        {
            player.coordinates.x += 1;
        }
        else return;
    }
}

void move_enemy(enemies_list& enemies_list_)
{
    for(int i = 0; i < enemies_list_.list.size(); i++)
    {
        int x_or_y = rand() % 2;
        int tmp_direction = rand() % 2;
        if(tmp_direction == 0) tmp_direction = -1;
        else tmp_direction = 1;

        if(x_or_y)
        {
            if(tmp_direction == 1 && enemies_list_.list[i].coordinates.x >= 0 && enemies_list_.list[i].coordinates.x < fieldsize - 2 )
            {
                enemies_list_.list[i].coordinates.x += tmp_direction;
            }
            if(tmp_direction == -1 && enemies_list_.list[i].coordinates.x > 0 && enemies_list_.list[i].coordinates.x < fieldsize - 1)
            {
                enemies_list_.list[i].coordinates.x += tmp_direction;
            }
        }
        if(!x_or_y)
        {
            if(tmp_direction == 1 && enemies_list_.list[i].coordinates.y >= 0 && enemies_list_.list[i].coordinates.y < fieldsize - 2 )
            {
                enemies_list_.list[i].coordinates.y += tmp_direction;
            }
            if(tmp_direction == -1 && enemies_list_.list[i].coordinates.y > 0 && enemies_list_.list[i].coordinates.y < fieldsize - 1)
            {
                enemies_list_.list[i].coordinates.y += tmp_direction;
            }
        }
    }
    return;
}

void print_battle_field(player& gamer, enemies_list& enemies_list_)
{
    for(int y = 0; y < fieldsize; y++)
    {
        for(int x = 0; x < fieldsize; x++)
        {

            for (int k = 0; k < enemies_list_.list.size(); k++)
            {
                if (x == gamer.coordinates.x && y == gamer.coordinates.y && gamer.HP > 0)
                {
                    std::cout << "P" << "  ";
                    x++;
                }
                if (x == enemies_list_.list[k].coordinates.x && y == enemies_list_.list[k].coordinates.y && enemies_list_.list[k].HP > 0)
                {
                    std::cout << "E" << "  ";
                    x++;
                    break;
                }
            }

            if (x < fieldsize && (x == gamer.coordinates.x && y == gamer.coordinates.y && gamer.HP > 0))
            {
                std::cout << "P" << "  ";
            }
            else if(x < fieldsize)
            {
                std::cout << "." << "  ";
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
    int x;
    int y;
    std::vector<int> init_coordinates_x;
    std::vector<int> init_coordinates_y;
    int pawn_quantity = enemy_quantity + 1;
    enemies_list enemies = {};

    //init coordinates list for objects
    for (int i = 0; i < pawn_quantity; i++)
    {
        int tmp;
        // set x coordinates;
        tmp = randomizer();
        for(int j = 0; j < init_coordinates_x.size(); j++)
        {
            while(tmp == init_coordinates_x[j])
            {
                tmp = randomizer();
            }
        }
        init_coordinates_x.push_back(tmp);
        std::cout << "X: " << tmp ;

        //set y coordinates;
        tmp = randomizer();
        for(int j = 0; j < init_coordinates_y.size(); j++)
        {
            while(tmp == init_coordinates_y[j])
            {
                tmp = randomizer();
            }
        }
        init_coordinates_y.push_back(tmp);
        std::cout << " Y: " << tmp << std::endl;
    }

    // initialize gamer and enemy objects on the field;
    // initialize gamer (with coordinates generated)
    player gamer = {"gamer", 100, 100, 10,
                    {gamer.coordinates.x = init_coordinates_x[0],gamer.coordinates.y = init_coordinates_y[0]}};

    //initialize enemies (with coordinates generated and rand() parameters)
    for (int i = 1; i < pawn_quantity; i++)
    {
        enemy enemy = {i, rand() % 100 + 50, rand() % 50, rand() % 15 + 15, {enemy.coordinates.x = init_coordinates_x[i],enemy.coordinates.y = init_coordinates_y[i]}};
        enemies.list.push_back({enemy});
    }

    // GAME STARTS HERE
    while(TRUE)
    {
        print_battle_field(gamer, enemies);
        std::cout << ":" << std::endl;
        std::cin >> user_input;

        if(user_input == "w" || user_input == "a" || user_input == "s" || user_input == "d")
        {
            move_player(gamer, user_input);
            gamer.HP++; // healing 1HP every tick;
        }

        move_enemy(enemies);


    }
    // GAME ENDS HERE

    return 0;
}