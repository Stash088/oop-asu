#include <iostream>
#include <string>

template <typename T, typename S>
class Pair
{
private:
    T x ;
    S y ;

public:
    Pair(const T& x, const S& y) : x (x) , y (y){}

    const T& first() const{ 
        return x;
    }
    const S& second() const{
        return y;
    }
};

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
    StringValuePair(const std::string& key, const S& value) : Pair<std::string, S> ( key, value){}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}