#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>


int fieldsize =  10; //set size of battlefield here
int enemy_quantity = 5; // set enemies on the field here

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
    int x_or_y = rand() % 2;

    for(int i = 0; i < enemies_list_.list.size(); i++)
    {
        int tmp_direction = rand() % 2;
        if(tmp_direction == 0) tmp_direction = -1;
        else tmp_direction = 1;

        if(x_or_y)
        {
            if(tmp_direction == 1 && (enemies_list_.list[i].coordinates.x >= 0 && enemies_list_.list[i].coordinates.x <= fieldsize - 2) )
            {
                enemies_list_.list[i].coordinates.x++;
            }
            if(tmp_direction == -1 && (enemies_list_.list[i].coordinates.x > 0 && enemies_list_.list[i].coordinates.x <= fieldsize - 1) )
            {
                enemies_list_.list[i].coordinates.x--;
            }
        }
        if(!x_or_y)
        {
            if(tmp_direction == 1 && (enemies_list_.list[i].coordinates.y >= 0 && enemies_list_.list[i].coordinates.y <= fieldsize - 2) )
            {
                enemies_list_.list[i].coordinates.y++;
            }
            if(tmp_direction == -1 && (enemies_list_.list[i].coordinates.y > 0 && enemies_list_.list[i].coordinates.y <= fieldsize - 1) )
            {
                enemies_list_.list[i].coordinates.y--;
            }
        }
    }
    return;
}

void take_damage(player& gamer, enemies_list& enemies_list_)
{
    for(int i = 0; i < enemies_list_.list.size(); i++)
    {
        if(gamer.coordinates.x == enemies_list_.list[i].coordinates.x && gamer.coordinates.y == enemies_list_.list[i].coordinates.y
            && enemies_list_.list[i].HP > 0)
        {
            std::cout << "\n~HIT~";

            gamer.AP -= enemies_list_.list[i].damage;
            if(gamer.AP <= 0)
            {
                gamer.HP += gamer.AP;
                gamer.AP = 0;
            }
            std::cout << std::endl << "Gamer HP: " << gamer.HP << " AP: " << gamer.AP;

            enemies_list_.list[i].AP -= gamer.damage;
            if(enemies_list_.list[i].AP <= 0)
            {
                enemies_list_.list[i].HP += enemies_list_.list[i].AP;
                enemies_list_.list[i].AP = 0;
            }
            if(enemies_list_.list[i].HP > 0)
            {
                std::cout << std::endl << i << " Enemy HP: " << enemies_list_.list[i].HP << " AP: " << enemies_list_.list[i].AP << std::endl << std::endl;
            }
            else
            {
                std::cout << std::endl;
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

void save_game(player& gamer, enemies_list& enemies)
{
    std::cout << "\nSAVING STARTED" ;

    std::ofstream file;
    int name_len = gamer.name.length();

    file.open("C:\\Users\\Poizone\\CLion_HW_24_5\\save.bin", std::ios::binary);
    file.write((char*)&name_len, sizeof(name_len));
    file.write(gamer.name.c_str(), gamer.name.length());
    file.write((char*)&gamer.HP, sizeof(int));
    file.write((char*)&gamer.AP, sizeof(int));
    file.write((char*)&gamer.damage, sizeof(int));
    file.write((char*)&gamer.coordinates.x, sizeof(int));
    file.write((char*)&gamer.coordinates.y, sizeof(int));
    for(int i = 0; i < enemies.list.size(); i++)
    {
        file.write((char*)&enemies.list[i].name, sizeof(int));
        file.write((char*)&enemies.list[i].HP, sizeof(int));
        file.write((char*)&enemies.list[i].AP, sizeof(int));
        file.write((char*)&enemies.list[i].damage, sizeof(int));
        file.write((char*)&enemies.list[i].coordinates.x, sizeof(int));
        file.write((char*)&enemies.list[i].coordinates.y, sizeof(int));
    }
    file.close();
    std::cout << std::endl << "GAME SAVED" << std::endl;
}

void load_game(player& gamer, enemies_list& enemies)
{
    std::cout << "\nSAVING STARTED\n" ;

    int name_len;
    std::ifstream file;
    file.open("C:\\Users\\Poizone\\CLion_HW_24_5\\save.bin", std::ios::binary);
    file.read((char*)&name_len, sizeof(name_len));
    gamer.name.resize(name_len);
    file.read((char*)gamer.name.c_str(), name_len);
    file.read((char*)&gamer.HP, sizeof(int));
    file.read((char*)&gamer.AP, sizeof(int));
    file.read((char*)&gamer.damage, sizeof(int));
    file.read((char*)&gamer.coordinates.x, sizeof(int));
    file.read((char*)&gamer.coordinates.y, sizeof(int));
    for(int i = 0; i < enemies.list.size(); i++)
    {
        file.read((char*)&enemies.list[i].name, sizeof(int));
        file.read((char*)&enemies.list[i].HP, sizeof(int));
        file.read((char*)&enemies.list[i].AP, sizeof(int));
        file.read((char*)&enemies.list[i].damage, sizeof(int));
        file.read((char*)&enemies.list[i].coordinates.x, sizeof(int));
        file.read((char*)&enemies.list[i].coordinates.y, sizeof(int));
    }
    file.close();
    std::cout << std::endl << "LOADIN COMPLITED" << std::endl;
}

int main()
{
    // init variables
    std::string user_input;
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
    player gamer = {"_game_boy_", 100, 150, 25,
                    {gamer.coordinates.x = init_coordinates_x[0],gamer.coordinates.y = init_coordinates_y[0]}};

    //initialize enemies (with coordinates generated and rand() parameters)
    for (int i = 1; i < pawn_quantity; i++)
    {
        enemy enemy = {i, rand() % 100 + 50, rand() % 50, rand() % 15 + 15, {enemy.coordinates.x = init_coordinates_x[i],enemy.coordinates.y = init_coordinates_y[i]}};
        enemies.list.push_back({enemy});
    }

    // GAME STARTS HERE
    std::cout << "To control type: w/a/s/d\nTo save type: save\nTo load last save type: load\n\n";
    std::cout << std::endl << "GAME STARTED" << std::endl;
    while(TRUE)
    {
        print_battle_field(gamer, enemies);

        std::cout << ":" << std::endl;
        std::cin >> user_input;

        if(user_input == "w" || user_input == "a" || user_input == "s" || user_input == "d")
        {
            move_player(gamer, user_input);
            if(gamer.AP <= 0) gamer.HP += rand() % 2; // healing 1HP, but not with every movement
        }
        else if(user_input == "save")
        {
            save_game(gamer, enemies);
            std::cout << "press w/a/s/d to continue\n\n" << std::endl;
            continue;
        }
        else if(user_input == "load")
        {
            load_game(gamer, enemies);
            std::cout << "press w/a/s/d to continue\n\n" << std::endl;
            continue;
        }

        move_enemy(enemies);
        take_damage(gamer, enemies);
        std::cout << std::endl << "HP: " << gamer.HP << " AP: " << gamer.AP << std::endl;

        //GAME OVER CHECK SECTION
        if(gamer.HP <= 0)
        {
            std::cout << std::endl << "YOU DIED" << std::endl;
            print_battle_field(gamer, enemies);
            break;
        }
        bool flag = FALSE;
        for(int i = 0, dead_enemies = 0; i < enemies.list.size(); i++)
        {
            if(enemies.list[i].HP <= 0) dead_enemies++;
            if(dead_enemies == enemies.list.size()) flag = TRUE;
        }
        if(flag)
        {
            std::cout << std::endl << "YOU WIN" << std::endl;
            print_battle_field(gamer, enemies);
            break;
        }
        // GAME OVER CHECK SECTION ENDS HERE
    }
    // GAME ENDS HERE

    return 0;
}