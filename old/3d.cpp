#include <iostream>

class Point3d
{
    double m_x;
    double m_y;
    double m_z;

public:
    void setvalues(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << "<" << m_x << "," << m_y << "," << m_z << ">" << std::endl;
    }

    bool isEqual(Point3d point2)
    {
        if(m_x == point2.m_x && m_y == point2.m_y && m_z == point2.m_z) {
            return true;
        } else {
            return false;
        }
    }
};

int main ()
{

    Point3d point;
    point.setvalues(1.0,2.0,3.0);

    Point3d point2;
    point2.setvalues(1.0,2.0,3.0);

    if (point.isEqual(point2)) {
        std::cout << "point1 is equal to point2" << std::endl;
    } else {
        std::cout << "point1 is not equal to point2" << std::endl;
    }

    Point3d point3;
    point3.setvalues(3.0,4.0,5.0);
    
    if (point.isEqual(point3)) {
        std::cout << "point1 is equal to point3" << std::endl;
    } else {
        std::cout << "point1 is not equal to point3" << std::endl;
    }
    return 0;
}
