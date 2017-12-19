#include <iostream>
#include <fstream>
#include <istream>
//using namespace std;
class A {
public:
	int value;
	friend std::ostream & operator << (std::ostream &, const A &);
	friend std::istream & operator >> (std::istream &, const A &);
};

std::ostream & operator << (std::ostream & stream, const A & a)
{
	stream << a.value;
	return stream;
}

std::istream & operator >> (std::istream &stream, const A & a)
{
	stream >> a.value;
	return stream;
}

int main() {
	A a;
	a.value = 5;
	std::ofstream fout;
	fout.open("file.txt");
	fout << a;

	std::ifstream fin;
	fin.open("file.txt");
	fin >> a;
	fout.close();
	system("pause");
	return 0;

}