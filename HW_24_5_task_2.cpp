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
    std::vector<int> rooms_meters_square = {};
    std::vector<int> room_height = {};
    std::vector<std::string> fireplace = {};
};

int main() {

    std::vector<buildings> area = {};

    std::cout << "Type number of areas:";
    int n;
    std::cin >> n;

    //init structed vector for areas with given number of areas
    for(int i = 0; i < n; i++)
    {
        area.push_back( {i, 0, {}, {}, {}, {}, {}, {}, {}, {}} );
    }

    // (AREA LEVEL) init with quantity of buildings in each area
    for(int current_area = 0, max = n; current_area < max; current_area++)
    {
        std::cout << "Type quantity of buildings in " << current_area+1 << " area:";
        std::cin >> n;
        area[current_area].quanity_of_buildings = n;

        // (BUILDING LEVEL) set name, sqare meters and floors amount for particular building
        for(int current_building = 0, max_buildings = n; current_building < max_buildings; current_building++)
        {
            std::string tmp_str_building_name;
            int tmp_int;

            std::cout << "\nType name of number " << current_building+1 << " building \n(home, garage, barn, sauna):";
            std::cin >> tmp_str_building_name;
            area[current_area].name.push_back(tmp_str_building_name);

            //check fireplace
            if(tmp_str_building_name == "home" || tmp_str_building_name == "sauna")
            {
                std::cout << "Is there a fireplace at " << tmp_str_building_name << " (yes / no) ? : ";
                std::string tmp_answer;
                std::cin >> tmp_answer;
                area[current_area].fireplace.push_back(tmp_answer);
            }
            else
            {
                area[current_area].fireplace.push_back("no");
            }//end-of-check fireplace

            std::cout << "\nType square meteres of " << tmp_str_building_name << " :";
            std::cin >> tmp_int;
            area[current_area].meters_square.push_back(tmp_int);

            std::cout << "Type quantity of floors in " << tmp_str_building_name << " :";
            std::cin >> tmp_int;
            area[current_area].floors.push_back(tmp_int);

            // (FLOOR LEVEL) when floors quantity are known , go through each floor and give it a number of rooms
            for(int current_floor = 0, max_floors = tmp_int; current_floor < max_floors; current_floor++)
            {
                std::cout
                << "Type quantity of rooms on the " << current_floor+1
                << " floor of " << tmp_str_building_name << " :";
                std::cin >> tmp_int;
                area[current_area].rooms_quantity_per_floor.push_back(tmp_int);

                //(ROOMS LEVEL) when number of rooms are known go through each room and give it a name, meters2 and height
                for(int current_room = 0, max_rooms = tmp_int; current_room < max_rooms; current_room++)
                {
                    std::string tmp_room_name_str;

                    std::cout
                    << "\nType name of room " << current_room+1
                    << " of " << current_floor+1
                    << " floor of " << tmp_str_building_name
                    << "\n(main, sleep, toilet, bath):";
                    std::cin >> tmp_room_name_str;
                    area[current_area].room_names.push_back(tmp_room_name_str);

                    std::cout
                    << "Type square meteres of " << tmp_room_name_str
                    << " on the " << current_floor+1
                    << " floor of " << tmp_str_building_name << " :";
                    std::cin >> tmp_int;
                    area[current_area].rooms_meters_square.push_back(tmp_int);

                    std::cout
                    << "Type height of " << tmp_room_name_str
                    << " room on the " << current_floor+1
                    << " floor of " << tmp_str_building_name << " :";
                    std::cin >> tmp_int;
                    area[current_area].room_height.push_back(tmp_int);

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

    //calculating total rooms in all buildings
    x = 0;
    for(int i = 0; i < area.size(); i++)
    {
        for(int j = 0; j < area[i].rooms_quantity_per_floor.size(); j++)
        {
            x += area[i].rooms_quantity_per_floor[j];
        }
    }
    std::cout << "\n\nTotal rooms for all buildings: " << x << std::endl;

    return 0;
}
