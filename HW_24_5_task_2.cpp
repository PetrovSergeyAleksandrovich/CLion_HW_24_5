#include <iostream>
#include <vector>

struct buildings
{
    int unique_number_area = 0;
    int quanity_of_buildings = 0;
    std::vector<std::string> name = {};
    std::vector<int> meters_square = {};
    std::vector<int> floors = {};
    std::vector<int> rooms_quantity_per_floor = {};
    std::vector<std::string> room_names = {};
};

int main() {

    std::vector<buildings> area = {};

    std::cout << "Type number of areas:";
    int n;
    std::cin >> n;

    //init vector for areas with given number of areas
    for(int i = 0; i < n; i++)
    {
        area.push_back( {i, 0, {}, {}, {}, {}, {}} );
    }

    // (AREA LEVEL) init with quantity of buildings in each area
    for(int i = 0, max = n; i < max; i++)
    {
        std::cout << "Type quantity of buildings in " << i+1 << " area:";
        std::cin >> n;
        area[i].quanity_of_buildings = n;

        // (BUILDING LEVEL) set name, sqare meters and floors amount for particular building
        for(int j = 0; j < n; j++)
        {
            std::string tmp_str_building_name;
            int tmp_int;
            std::cout << "\nType name of number " << j+1 << " building \n(home, garage, barn, sauna):";
            std::cin >> tmp_str_building_name;
            area[i].name.push_back(tmp_str_building_name);
            std::cout << "\nType square meteres of " << tmp_str_building_name << " :";
            std::cin >> tmp_int;
            area[i].meters_square.push_back(tmp_int);
            std::cout << "Type quantity of floors in " << tmp_str_building_name << " :";
            std::cin >> tmp_int;
            area[i].floors.push_back(tmp_int);

            // (FLOOR LEVEL) when floors quantity are known , go through each floor and give it a number of rooms
            for(int k = 0, max_1 = tmp_int; k < max_1; k++)
            {
                std::cout << "Type quantity of rooms on the " << k+1 << " floor of " << tmp_str_building_name << " :";
                std::cin >> tmp_int;
                area[i].rooms_quantity_per_floor.push_back(tmp_int);

                //(ROOMS LEVEL) when number of rooms are known go through each room and give it a name
                for(int m = 0, max_2 = tmp_int; m < max_2; m++)
                {
                    std::string tmp_room_name_str;
                    std::cout << "\nType name of room " << m+1 << " of " << k+1 << " floor of " << tmp_str_building_name
                    <<" \n(main, sleep, toilet, bath):";
                    std::cin >> tmp_room_name_str;
                    area[i].room_names.push_back(tmp_room_name_str);
                }// (ROOMS LEVEL)
            }// (FLOOR LEVEL)
        }// (BUILDING LEVEL)
    }// (AREA LEVEL)

    //just a simple check for output
    std::cout
    << "\nArea: " << area[0].unique_number_area
    << "\nBuildings total in area: "<< area[0].quanity_of_buildings
    << "\nName of the first building: " << area[0].name[0]
    << "\nFloors in building: " << area[0].floors[0]
    << "\nRooms at 1st floor: " << area[0].rooms_quantity_per_floor[0]
    << "\nRoom 1 at 1st floor: " << area[0].room_names[0] << std::endl;

    //calculating total sqare meters under all buildings in each area
    int x = 0;
    for(int i = 0; i < area.size(); i++)
    {
        for(int j = 0; j < area[i].meters_square.size(); j++)
        {
            x += area[i].meters_square[j];
        }
    }
    std::cout << "\n\nTotal square meters for all buildings: " << x << std::endl;

    return 0;
}
