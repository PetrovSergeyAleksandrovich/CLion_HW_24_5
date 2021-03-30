#include <iostream>
#include <vector>

enum room_type
{
    living,
    children,
    bedroom,
    kitchen,
    toilet,
    bathroom,
};

enum building_type
{
    house,
    garage,
    bathhouse,
    barn,
};

struct room
{
    double area;
    room_type type;
};

struct store
{
    double height;
    std::vector<room> rooms;
};

struct building
{
    bool has_chimney;
    double area;
    building_type type;
    std::vector<store> stores;
};

struct plot
{
    int number;
    std::vector<building> buildings;
    double area;
};

struct village
{
    std::vector<plot> plots;
};

building_type set_building_type(std::string s)
{
    if(s == "house") return building_type::house;
    if(s == "garage") return building_type::garage;
    if(s == "bathhouse") return building_type::bathhouse;
    if(s == "barn") return building_type::barn;
}

std::string get_building_type(building_type type)
{
    std::string tmp;
    if(type == building_type::house ) {tmp = "house"; return tmp;}
    if(type == building_type::garage ) {tmp ="garage"; return tmp;}
    if(type == building_type::bathhouse ) {tmp = "bathhouse"; return tmp;}
    if(type == building_type::barn ) {tmp ="barn"; return tmp;}
}

bool set_chimney(std::string s)
{
    if(s == "y") return true;
    if(s == "n") return false;
}

room_type set_room_type(std::string s)
{
    if(s == "bathroom") return room_type::bathroom;
    if(s == "bedroom") return room_type::bedroom;
    if(s == "children") return room_type::children;
    if(s == "kitchen") return room_type::kitchen;
    if(s == "living") return room_type::living;
    if(s == "toilet") return room_type::toilet;
}

std::string get_room_type(room_type type)
{
    std::string tmp;
    if(type == room_type::bathroom ) {tmp = "bathroom"; return tmp;}
    if(type == room_type::bedroom ) {tmp = "bedroom"; return tmp;}
    if(type == room_type::children ) {tmp = "children"; return tmp;}
    if(type == room_type::kitchen ) {tmp = "kitchen"; return tmp;}
    if(type == room_type::living ) {tmp = "living"; return tmp;}
    if(type == room_type::toilet ) {tmp = "toilet"; return tmp;}
}

int main()
{
    int n;
    double m;
    bool b;
    std::string s;
    village ryabushki;

    std::cout << "Type number of AREAS in village RYABUSHKI : ";
    std::cin >> n;

    for(int current_plot = 0, max_plots = n; current_plot < max_plots; current_plot++)
    {
        ryabushki.plots.push_back({});
        ryabushki.plots[current_plot].number = current_plot;
        std::cout << "\nType square meters of full " << current_plot << " TERRITORY: ";
        std::cin >> m;
        ryabushki.plots[current_plot].area = m;

        std::cout << "\nType quantity of buildings on " << current_plot << " TERRITORY: ";
        std::cin >> n;

        for(int current_building = 0, max_buildings = n; current_building < max_buildings; current_building++)
        {
            ryabushki.plots[current_plot].buildings.push_back({});
            std::cout << "\nWhat's type of " << current_building << " building house/garage/bathhouse/barn: ";
            std::cin >> s;
            ryabushki.plots[current_plot].buildings[current_building].type = set_building_type(s);

            std::cout << "\nDoes " << current_building << " has chimney?  y/n :";
            std::cin >> s;
            ryabushki.plots[current_plot].buildings[current_building].has_chimney = set_chimney(s);

            std::cout << "\nHow many square meters under " << get_building_type(ryabushki.plots[current_plot].buildings[current_building].type) << " building? :";
            std::cin >> m;
            ryabushki.plots[current_plot].buildings[current_building].area = m;

            std::cout
            << "\nType quantity of floors in "
            << get_building_type(ryabushki.plots[current_plot].buildings[current_building].type) << " building: ";
            std::cin >> n;

            for(int current_floor = 0, max_floors = n; current_floor < max_floors; current_floor++)
            {
                ryabushki.plots[current_plot].buildings[current_building].stores.push_back({});
                std::cout << "\nType height of  " << current_floor+1 << " floor: ";
                std::cin >> m;
                ryabushki.plots[current_plot].buildings[current_building].stores[current_floor].height = m;

                std::cout << "\nType quantity of rooms on " << current_floor+1 << " : ";
                std::cin >> n;

                for(int current_room = 0, max_rooms = n; current_room < max_rooms; current_room++)
                {
                    ryabushki.plots[current_plot].buildings[current_building].stores[current_floor].rooms.push_back({});
                    std::cout << "\nWhat's type of " << current_room+1 << " room living, children, bedroom, kitchen, toilet bathroom: ";
                    std::cin >> s;
                    ryabushki.plots[current_plot].buildings[current_building].stores[current_floor].rooms[current_room].type = set_room_type(s);

                    std::cout << "\nWhat's square meters for " << get_room_type(ryabushki.plots[current_plot].buildings[current_building].stores[current_floor].rooms[current_room].type) << " room ?: ";
                    std::cin >> m;
                }

            }
        }
    }

    int total_meters = 0;
    for(int i = 0; i < ryabushki.plots.size(); i++)
    {
        total_meters += ryabushki.plots[i].area;
    }
    std::cout << "\nTotal sqare meters for all plots are: " << total_meters;

    double total_meters_buildings = 0;
    for(int i = 0; i < ryabushki.plots.size(); i++)
    {
        for(int j = 0; j < ryabushki.plots[i].buildings.size() ; j++)
        {
            total_meters_buildings += ryabushki.plots[i].buildings[j].area;
        }
    }
    std::cout << "\nTotal sqare meters for all buildings are: " << total_meters_buildings;

    return 0;
}