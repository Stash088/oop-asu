#include <iostream>
#include <string>
using namespace std;

class Fruit{
public:
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

class GrannySmith : public Apple{
public:
	GrannySmith(string color) : Apple("Apple",color){}
	string getColor(){	
	    return "Granny Smith is " + Apple::getColor();	
	}
};

int main(){
  Apple a("Apple" , "Red");
  Banana b("Banana" , "Yellow");
  GrannySmith g("red");
  cout << "My " << a.getName() << " is " << a.getColor() << endl;
  cout << "My " << b.getName() << " is " << b.getColor() << endl;
  cout << "My " << g.getColor();
  return 0;
}
