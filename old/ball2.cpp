#include <string>
#include <iostream>

using namespace std;

class Ball
{
private:
    std::string m_color = "black";
    double m_radius = 10.0;
                 
public:
    //Default constructor with no parameters
    
    Ball()
    {
    }

    Ball(string color, double rad)
        :m_color(color), m_radius(rad)
    {
    }

    Ball(string color)
        :m_color(color)
    {
    }

    Ball(double rad)
        :m_radius(rad)
    {
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
    };

int main()
{
    Ball def;
    def.print();

    Ball blue("blue");
    blue.print();

    Ball twenty(20.0);
    twenty.print();

    Ball blueTwenty("blue", 20.0);
    blueTwenty.print();

    return 0;
}
