#include <iostream>
#include <vector>

struct vec
{
    std::vector<double> x = {};
    std::vector<double> y = {};
    int scale = 0;
};

void add(double& x1, double& x2, double& y1, double& y2)
{
    std::cout << "result of 'add' = " << x1 + x2 << " , " << y1 + y2 << " ) ";
}

void subtract(double& x1, double& x2, double& y1, double& y2)
{
    std::cout << "result of 'subtract' = " << x1 - x2 << " , " << y1 - y2 << " ) ";
}

void scale(double& x1, double& y1, int& scale)
{
    std::cout << "result of 'scale' = " << x1 * scale << " , " << y1 * scale << " ) ";
}

void length(double& x1, double& y1)
{
    std::cout << "result of 'length' = " << sqrt( ((x1 * x1) + (y1 * y1)) );;
}

void normalize(double& x1, double& y1)
{
    std::cout
    << "result of 'normalize' = "
    << x1 / sqrt( ((x1 * x1) + (y1 * y1)) )
    << " , "
    << y1 / sqrt( ((x1 * x1) + (y1 * y1)) );
}

int main()
{
    vec a = {};
    double tmp;

    std::string user_input;
    std::cout << "your command\nadd/subtract/scale/length/normalize\n: ";
    std::cin >> user_input;

    if(user_input == "add")
    {
        std::cout << "input first vector coordinate X : ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input first vector coordinate Y : ";
        std::cin >> tmp;
        a.y.push_back(tmp);
        std::cout << "input second vector coordinate X : ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input second vector coordinate Y : ";
        std::cin >> tmp;
        a.y.push_back(tmp);

        add(a.x[0], a.x[1], a.y[0], a.y[1] );
    }

    if(user_input == "subtract")
    {
        std::cout << "input first vector coordinate X : ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input first vector coordinate Y : ";
        std::cin >> tmp;
        a.y.push_back(tmp);
        std::cout << "input second vector coordinate X : ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input second vector coordinate Y : ";
        std::cin >> tmp;
        a.y.push_back(tmp);

        subtract(a.x[0], a.x[1], a.y[0], a.y[1] );
    }

    if(user_input == "scale")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.push_back(tmp);
        std::cout << "input scale value: ";
        std::cin >> a.scale;

        scale(a.x[0], a.y[0], a.scale);
    }

    if(user_input == "length")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.push_back(tmp);

        length(a.x[0], a.y[0]);
    }

    if(user_input == "normalize")
    {
        std::cout << "input first vector coordinate X: ";
        std::cin >> tmp;
        a.x.push_back(tmp);
        std::cout << "input first vector coordinate Y: ";
        std::cin >> tmp;
        a.y.push_back(tmp);

        normalize(a.x[0], a.y[0]);
    }

    return 0;
}

