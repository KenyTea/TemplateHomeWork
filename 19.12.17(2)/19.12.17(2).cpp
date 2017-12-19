#include <iostream>
#include <fstream>
//using namespace std;
class A {
public:
	int value;
	friend std :: ostream & operator << (std::ostream &, const A & );

};

std::ostream & operator << ( std::ostream & stream, const A & a )
{
	stream << a.value;
	return stream;
}

int main() {
	A a;
	a.value = 5;
	std::ofstream fout;
	fout.open("file.txt");
	fout << a;
	fout.close();
	system("pause");
	return 0;

}