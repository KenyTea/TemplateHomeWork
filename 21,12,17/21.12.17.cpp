#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include<algorithm> // for sort
#include <unordered_map>
#include <array>

// lymbda
//class A {
//public:
//	A() {
//		std::cout << "A()" << std::endl;
//	}
//	A(int x): value(x){}
//	~A() {
//		std::cout << "~A(int)" << std::endl;
//	}
//	int value;
//	friend std::ostream & operator << (std::ostream &, const A &);
//	friend void operator >> (std::istream & stream, const A & a);
//
//	void Show() {
//
//		std::cout << value << std::endl;
//	}
//
//};
//std::ostream & operator << (std::ostream & stream, const A & a) {
//	return stream << a.value;
//}
//void operator >> (std::istream & stream, const A & a) {
//	stream >> a;
//} 
//
//
//
//int main() {
//
//	std::vector<A> x = { A(1), A(2) ,A(3) };
//	x.push_back(A(6));
//	x.shrink_to_fit();
//	x.pop_back();
//	x.pop_back();
//	std::cout << x.size() << std::endl;
//	std::cout << x.max_size() << std::endl;
//	int y;
//	std::cin >> y;
//	
//	auto a = std::find_if(x.begin(), x.end(), [y](A & a) {return a.value == y; }); // Lambda - [y](A & a) {return a.value == y; }
//	std::cout << std::endl;
//
//	if (a != x.end()) {
//		std::cout << *a << '\n';
//	}
//	else std::cout << "not found" << std::endl;
//
//	system("pause");
//	return 0;
//}


// Lambda.cpp : Defines the entry point for the console application.
//



//class A {
//public:
//	A() {
//		std::cout << "A()" << std::endl;
//	}
//	A(int x) : value(x) {
//		std::cout << "A(int)" << std::endl;
//	}
//	~A() {
//		std::cout << "~A()" << std::endl;
//	}
//	int value;
//	friend std::ostream & operator<<(std::ostream &, const A &);
//	friend void operator>>(std::istream & stream, const A & a);
//};
//std::ostream & operator<<(std::ostream & stream, const A & a)
//{
//	return stream << a.value;
//}
//void operator>>(std::istream & stream, const A & a) {
//	stream >> a;
//}
//class Finder {
//public:
//	Finder(int y) : x(y) {}
//	int x;
//	bool operator()(const A & a) {
//		return x == a.value;
//	}
//};
//
//int main()
//{
//	std::vector<A> x = { A(1), A(2), A(3) };
//	std::for_each(x.begin(), x.end(), [](A a) { std::cout << a.value << '\t'; });
//	std::cout << std::endl;
//	int y;
//	std::cin >> y;
//	Finder f(y);
//	auto a = std::find_if(x.begin(), x.end(), f);
//	auto b = std::find_if(x.begin(), x.end(), [y](A & a) {return a.value == y; });
//	if (a != x.end()) {
//		std::cout << *a << '\t' << *b << std::endl;
//	}
//	else {
//		std::cout << "not found" << std::endl;
//	}
//	return 0;
//}

void Foo(std::array<char, 5> x, std::array<char, 5> y) {
	if (std::is_permutation(x.begin(), x.end(), y.begin())) {
		std::cout << "The same elements.\n" << std::endl;
	}
	else std::cout << "Don't have same elements.\n";

}

int main() {
	//-----------------------------------------------------
	// Muslim's version check unic O(n2) and O(n)
	std::string s = "123456789";
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < s.length(); ++j) {
			if (i != j && s[i] == s[j]) {
				std::cout << "not unique";
				return 0;
			}
		}
	}
	s = "1223456789";
	bool arr[256] = { false };
	for (int i = 0; i < s.length(); ++i) {
		int temp = (int)(s[i] - 48);
		if (arr[temp]) {
			std::cout << "not unique";
			return 0;
		}
		arr[temp] = true;
	}

	std::cout << "unique";
	return 0;
//--------------------------------------------------------------
	std::array<char, 5> a = { 'a','b','c','d','e' };
	std::array<char, 5> b = { 'b','a','c','d','e' };
	std::array<char, 5> c = { 'c','b','a','d','e' };
	std::array<char, 5> d = { 'd','b','a','c','e' };
	std::array<char, 5> e = { 'e','d','b','c','a' };

	Foo(a, b);
	Foo(b, c);
	Foo(c, d);
	Foo(d, e);
	Foo(e, a);

	/*if (std::is_permutation(A.begin(), A.end(), B.begin())) {
		std::cout << "A and B contain the same elements.\n" << std:: endl;
	}
	else std::cout << "A and B contain the don't have same elements.\n";

	if (std::is_permutation(B.begin(), B.end(), C.begin())) {
		std::cout << "B and C contain the same elements.\n" << std::endl;
	}
	else std::cout << "B and C contain the don't have same elements.\n";

	if (std::is_permutation(C.begin(), C.end(), D.begin())) {
		std::cout << "C and D contain the same elements.\n" << std::endl;
	}
	else std::cout << "C and D contain the don't have same elements.\n";

	if (std::is_permutation(D.begin(), D.end(), E.begin())) {
		std::cout << "D and C contain the same elements.\n" << std::endl;
	}
	else std::cout << "D and C contain the don't have same elements.\n";

	if (std::is_permutation(E.begin(), E.end(), A.begin())) {
		std::cout << "E and A contain the same elements.\n" << std::endl;
	}
	else std::cout << "E and A contain the don't have same elements.\n";
*/
	system("pause");
	return 0;
}