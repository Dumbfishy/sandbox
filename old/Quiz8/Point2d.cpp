#include <iostream>
#include <cmath>

using namespace std;

class Point2d
{

private: 
	double m_x, m_y;
public:
    Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}

    void print()
    {
        cout << "Point2d(" << m_x << ", " << m_y << ") " << endl;
    }

    double distanceTo(Point2d &p2)
    {
        return sqrt((m_x - p2.m_x)*(m_x - p2.m_x) + (m_y - p2.m_y)*(m_y - p2.m_y));
    }

    friend double distanceFrom(Point2d &p1, Point2d &p2);

};

double distanceFrom(Point2d &p1, Point2d &p2)
{
    return sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
}


int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
 
    cout << "Distance between two points: " << first.distanceTo(second) << endl;
    cout << "Distance between two points: " << distanceFrom(first, second) << endl;
    return 0;
}
