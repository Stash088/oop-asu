#include <iostream>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    
public:
    Point(int x, int y) : x(x) , y(y){}
    
    void Show(){ 
        cout << "Point "<<": ("<< x <<", "<< y <<")"<< endl;
    }
};

int main(){
    Point a;
    Point b(3, 4);
    b.Show();
    a.Show();
    return 0;
}