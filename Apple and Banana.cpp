#include <iostream>
#include <string>
using namespace std;

class Fruit{
private:
    string name;
    string color;
public:
    Fruit(string name , string color) : name(name) , color(color) {}
    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

class Apple : public Fruit{
public:
    Apple(string name , string color): Fruit(name,color){}
};

class Banana : public Fruit{
public:
    Banana(string name , string color): Fruit(name,color){}
};

int main(){
  Apple a("Apple" , "Red");
  Banana b("Banana" , "Yellow");
  cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
  cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  return 0;
}
