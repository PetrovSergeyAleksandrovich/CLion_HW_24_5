#include <iostream>
#include <fstream>

enum command
{
    list,
    add
};

command user_action_f()
{
    std::string command = "none";
    while(command != "add" && command != "list")
    {
        std::cout << "\ntype 'add' or 'list' to make action: ";
        std::cin >> command;
        if(command == "add")
        {
            return add;
        }
        else if(command == "list")
        {
            return list;
        }
    }
}

struct people
{
    std::string name = "unknown";
    std::string family = "unknown";
    std::string date = "unknown";
    int rubles = 0;
};

int main()
{
    command user_command = user_action_f();
    people person;

    if(user_command == list)
    {
        std::ifstream from_file;
        from_file.open("C:\\Users\\Poizone\\CLion_HW_24_5\\payments.txt");
        while(!from_file.eof())
        {
            std::string tmp;
            person.name = "";
            from_file >> person.name >> person.family >> person.date >> person.rubles;
            if(person.name == "") break;
            std::cout << person.name << " " << person.family << " " << person.date << " "<< person.rubles << std::endl;
        }
        from_file.close();
    }

    if(user_command == add)
    {
        std::ofstream to_file;
        to_file.open("C:\\Users\\Poizone\\CLion_HW_24_5\\payments.txt", std::ios::app);
        std::cout << "\ntype info in format 'name family date rubles'\n: ";
        std::cin >> person.name >> person.family >> person.date >> person.rubles;
        to_file << person.name << " " << person.family << " " << person.date << " "<< person.rubles << std::endl;
    }

}

