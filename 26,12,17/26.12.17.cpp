#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Meet 28
class Country;
class City;
//class Country
//{
//	std::vector<City> cityes;
//};
//class City : public Country 
//{public:
//	std::string name;
//};

class City {
public:
	std::string name;
	std::string country;
	std::vector <City> cityes;
	City(std::string country, std::string name) {
		this->country = country;
		this->name = name;
	}

	friend std::ostream & operator << (std::ostream & stream,const  City & city);

	

};

class Manager {
public:
	std::vector<City> cityes;
	Manager() {
		City city("Kazakhstan", "Alaty");
		cityes.push_back(city);
		City city1("Kazakhstan", "Astana");
		cityes.push_back(city1);
		
	}

	void writeToFilt() {
		std::ofstream fout("Country.txt");
		std::for_each(cityes.begin(), cityes.end(), [&fout](const City & city) {
			if (fout.is_open()) {
				fout << city;
		}
			});
	}

	void readFile() {
		std::ifstream fin("Country.txt");
		if (fin.is_open()) 
		{
			while (fin.eof()) 
			{
				std::string str;
				std::getline(fin, str);
				auto pos = str.find_first_of(' ');
				cityes.push_back(
					City(
					std::string{ str.begin(), str.begin() + pos },
					std::string{ str.begin() + pos + 1, str.end() - 1 }
				)
				);
			}
		}

	}
	
	friend std::ostream & operator << (std::ostream & stream, Manager & manager);

};

int main() {
	
	std::vector <City> cityes;
	Manager man;
	man.writeToFilt();
	man.readFile();

	std::cout << man;
	std::cout << man.cityes.size();


	system("pause");
	return 0;
}

std::ostream & operator<<(std::ostream & stream, const City & city)
{
	return stream << city.country << "  " << city.name << std::endl;
}

std::ostream & operator <<(std::ostream & stream,  Manager & manager)
{
	std::for_each(manager.cityes.begin(), manager.cityes.end(), [&stream] (const City & city)
	{
		stream << city.country << "  " << city.name << std::endl;
	});
	return stream;
}

