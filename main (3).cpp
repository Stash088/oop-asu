#include <iostream>
#include <string>
#include <vector>
 

class Doctor;
 
class Patient
{
private:
	std::string m_name;
	std::vector<Doctor *> m_doctor; // благодаря вышеприведенному предварительному объявлению Doctor, эта строка не вызовет ошибку компиляции
 
	// Мы объявляем метод addDoctor() закрытым, так как не хотим его публичного использования.
	// Вместо этого доступ к нему будет осуществляться через Doctor::addPatient().
	// Мы определим этот метод после определения класса Doctor, так как нам сначала нужно определить Doctor, чтобы использовать что-либо, связанное с ним
	void addDoctor(Doctor *doc);
 
public:
	Patient(std::string name)
		: m_name(name)
	{
	}
 
	// Мы реализуем перегрузку оператора вывода ниже определения класса Doctor, так как он как раз и требуется для реализации перегрузки
	friend std::ostream& operator<<(std::ostream &out, const Patient &pat);
 
	std::string getName() const { return m_name; }
 
	// Мы делаем класс Doctor дружественным, чтобы иметь доступ к закрытому методу addDoctor().
	// Примечание: Мы бы хотели сделать дружественным только один метод addDoctor(), но мы не можем это сделать, так как Doctor предварительно объявлен
	friend class Doctor;
};
 
class Doctor
{
private:
	std::string m_name;
	std::vector<Patient *> m_patient;
 
public:
	Doctor(std::string name):
		m_name(name)
	{
	}
 
	void addPatient(Patient *pat)
	{
		// Врач добавляет Пациента
		m_patient.push_back(pat);
		
		// Пациент добавляет Врача
		pat->addDoctor(this);
	}
 
 
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doc)
	{
		unsigned int length = doc.m_patient.size();
		if (length == 0)
		{
			out << doc.m_name << " has no patients right now";
			return out;
		}
 
		out << doc.m_name << " is seeing patients: ";
		for (unsigned int count = 0; count < length; ++count)
			 out << doc.m_patient[count]->getName() << ' ';
 
		return out;
	}
 
	std::string getName() const { return m_name; }
};
 
void Patient::addDoctor(Doctor *doc)
{
	m_doctor.push_back(doc);
}
 
std::ostream& operator<<(std::ostream &out, const Patient &pat)
{
	unsigned int length = pat.m_doctor.size();
	if (length == 0)
	{
		out << pat.getName() << " has no doctors right now";
		return out;
	}
 
	out << pat.m_name << " is seeing doctors: ";
	for (unsigned int count = 0; count < length; ++count)
		out << pat.m_doctor[count]->getName() << ' ';
 
	return out;
}
 
 
int main()
{
	// Создаем Пациентов вне области видимости класса Doctor
	Patient *p1 = new Patient("Anton");
	Patient *p2 = new Patient("Ivan");
	Patient *p3 = new Patient("Derek");
 
	// Создаем Докторов вне области видимости класса Patient
	Doctor *d1 = new Doctor("John");
	Doctor *d2 = new Doctor("Tom");
 
	d1->addPatient(p1);
 
	d2->addPatient(p1);
	d2->addPatient(p3);
 
	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';
	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';
 
	delete p1;
	delete p2;
	delete p3;
	
	delete d1;
	delete d2;
 
	return 0;
}