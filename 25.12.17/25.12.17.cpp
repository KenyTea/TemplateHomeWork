#include <iostream>
using namespace std;
class Singleton 
{
public:
	static Singleton & getInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton() {}
	

	Singleton(const Singleton &) = delete;

	Singleton & operator = (const Singleton &) = delete;
};


int main() {
	Singleton & x = Singleton::getInstance();
	Singleton & y = Singleton::getInstance();
	Singleton & z = Singleton::getInstance();
	//auto x = Singleton::getInstance();

	cout << &x << endl << &y << endl << &z << endl;

	system("pause");
	return 0;
}