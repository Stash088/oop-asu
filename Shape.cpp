#include <iostream>
 
class Point
{
private:
    int x;
    int y;
    int z;
 
public:
    Point(int x, int y, int z) : x(x) , y(y) , z(z){}
 
    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.x << ", " << p.y << ", " << p.z << ')';
    }
};
 
class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Shape& p)
    {
        return p.print(out);
    }
    virtual ~Shape() = default;
};
 
class Triangle : public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;
 
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3) : m_p1(p1), m_p2(p2), m_p3(p3){}
 
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
    }
};
 
class Circle : public Shape
{
private:
    Point m_center;
    int m_radius;
 
public:
    Circle(const Point& center, int radius): m_center(center), m_radius(radius){}
 
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Circle(" << m_center << ", radius " << m_radius << ')';
    }
};
 
int main()
{
    Circle c{ Point{1, 2, 3}, 7 };
    std::cout << c << '\n';
 
    Triangle t{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9} };
    std::cout << t << '\n';
 
    return 0;
}
