// MPI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

int main()
{
		ifstream fin("file.txt");
		string str;

		if (fin.is_open()) {
			while (getline(fin, str))
			{
				cout << endl << endl << str << endl << endl << endl << endl;//t >> str;
			}
		} fin.close();


		getline(cin, str);
		ofstream fout;
		//fout.open("file.txt"); // трёт
		fout.open("file.txt", ios::app); // не трёт (дописывает)

		if (fout.is_open()) {

			fout << str;
		}
		fout.close();
	//ifstream S("file.txt");
	//string str;
	//if (S.is_open()) {
	//	while (getline(S, str)) {
	//		cout << str << endl;
	//	}		
	//}
	//S.close();

	//ofstream O("file.txt");
	//string s;
	//cin >> s;
	//while (getline(cin, s)) {
	//	if (s != "exit") {
	//		O << s;
	//	}
	//	else { break; }
	//}
	//O.clear();
	////cout << str << endl;
    return 0;
}

