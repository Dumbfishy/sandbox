#include <iostream>
#include <string>

class Ball 
{
private: 
    std::string m_color;
    double m_radius;

public:
    Ball(std::string color = "Black", double rad = 10.0)
    {
        m_color = color;
        m_radius = rad;
    }

    Ball(double rad)
    {
        m_color = "Black";
        m_radius = rad;
    }

    void print()
    {
        std::cout << "color: " << m_color;
        std::cout << ", radius: " << m_radius << std::endl;
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
