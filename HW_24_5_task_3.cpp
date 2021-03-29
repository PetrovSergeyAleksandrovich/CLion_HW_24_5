#include <iostream>
#include <vector>
#include <math.h>

struct x_coordinates
{
    std::vector<double> x = {};
};

struct y_coordinates
{
    std::vector<double> y = {};
};

struct vec
{
    x_coordinates x = {};
    y_coordinates y = {};
    int scale = 0;
};


int main()
{

    vec a{};
    double tmp;
    int tmp_scale;

    std::string user_input;
    std::cout << "your command\nadd/subtract/scale/length/normalize\n: ";
    std::cin >> user_input;

    if(user_input == "add")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);
        std::cout << "input second vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input second vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);

        std::cout << "result of 'add' = ( " << a.x.x[0] + a.x.x[1] << " , " << a.y.y[0] + a.y.y[1] << " ) ";
    }

    if(user_input == "subtract")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);
        std::cout << "input second vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input second vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);

        std::cout << "result of 'subtract' = ( " << a.x.x[0] - a.x.x[1] << " , " << a.y.y[0] - a.y.y[1] << " ) ";
    }

    if(user_input == "scale")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);
        std::cout << "input scale value: ";
        std::cin >> tmp_scale;
        a.scale = tmp_scale;

        std::cout << "result of 'scale' = ( " << a.x.x[0] * a.scale << " , " << a.y.y[0] * a.scale << " ) ";
    }

    if(user_input == "length")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.y.push_back(tmp);

        std::cout << "result of 'length' = " << sqrt( (a.x.x[0] * a.x.x[0]) + (a.y.y[0] * a.y.y[0]) );
    }

    return 0;
}

