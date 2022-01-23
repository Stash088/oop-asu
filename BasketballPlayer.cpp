#include <iostream>
#include <string>
 
class Human
{
public:
    std::string m_name;
    int m_age;
 
    Human(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {
    }
 
    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
 
};
 
// BasketballPlayer открыто наследует Human
class BasketballPlayer : public Human
{
public:
    double m_gameAverage;
    int m_points;
 
    BasketballPlayer(double gameAverage = 0.0, int points = 0)
       : m_gameAverage(gameAverage), m_points(points)
    {
    }
};
 
int main()
{
    // Создаем нового Баскетболиста
    BasketballPlayer anton;
    // Присваиваем ему имя (мы можем делать это напрямую, так как m_name является public)
    anton.m_name = "Anton";
    // Выводим имя Баскетболиста
    std::cout << anton.getName() << '\n'; // используем метод getName(), который мы унаследовали от класса Human
 
    return 0;
}
