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
	ifstream S("file.txt");
	string str;
	if (S.is_open()) {
		while (getline(S, str)) {
			cout << str << endl;
		}		
	}
	//cout << str << endl;
    return 0;
}

