#include <iostream>
#include <string>
 
class Car
{
private:
	std::string m_name;
	int m_id;
 
public:
	Car(std::string name, int id)
		: m_name(name), m_id(id)
	{
	}
 
	std::string getName() { return m_name; }
	int getId() { return m_id;  }
};
 
// Наш CarLot, по сути, является статическим массивом, содержащим Автомобили, и имеет функцию для "выдачи" Автомобилей.
// Поскольку массив является статическим, то нам не нужно создавать объекты для использования класса CarLot
class CarLot
{
private:
	static Car s_carLot[4];
 
public:
	CarLot() = delete;
 
	static Car* getCar(int id)
	{
		for (int count = 0; count < 4; ++count)
			if (s_carLot[count].getId() == id)
				return &(s_carLot[count]);
		
		return nullptr;
	}
};
 
Car CarLot::s_carLot[4] = { Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 58) };
 
class Driver
{
private:
	std::string m_name;
	int m_carId; // для связывания классов, вместо указателя, используется Идентификатор (целочисленное значение)
 
public:
	Driver(std::string name, int carId)
		: m_name(name), m_carId(carId)
	{
	}
 
	std::string getName() { return m_name; }
	int getCarId() { return m_carId; }
 
};
 
int main()
{
	Driver d("Ivan", 14); // Ivan использует машину с ID 14
 
	Car *car = CarLot::getCar(d.getCarId()); // получаем этот Автомобиль из CarLot
	
	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";
 
	return 0;
}
