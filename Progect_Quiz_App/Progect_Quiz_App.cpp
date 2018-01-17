// Progect_Quiz_App.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

class Question // class for keep questtions, variants & correct answer
{
public:
	std::string content;
	std::string variants[4];
	std::string right;
};

class Quiz
{

public:

	std::vector<Question> questions; // vector whith questions

	void mathematics() {
		std::ifstream fin("mathematics.txt"); // create file and read it
		if (!fin.is_open())  // check file
		{
			std::cout << "The file not found" << std::endl;
		}
		else {
			std::string temp; // creat temp string
			while (!fin.eof()) {
				getline(fin, temp); //read first string 
				if (temp == "") {
					break;
				}
				Question q; // creat Question's object
				q.content = temp; // write the read string to the created variable for the question

				for (int i = 0; i < 4; ++i) {
					getline(fin, temp); // read variants 
					q.variants[i] = temp; // wright variants
				}
				getline(fin, temp); // read right unswer
				q.right = temp; // write unswer to temp
				questions.push_back(q);
			}
		}
		fin.close();
	}

	void PC()
	{
		std::ifstream fin("PC.txt"); // create file and read it
		if (!fin.is_open())  // check file
		{
			std::cout << "The file not found" << std::endl;
		}
		else {
			std::string temp; // creat temp string
			while (!fin.eof()) {
				getline(fin, temp); //read first string 
				if (temp == "") {
					break;
				}
				Question q; // creat Question's object
				q.content = temp; // write the read string to the created variable for the question

				for (int i = 0; i < 4; ++i) {
					getline(fin, temp); // read variants 
					q.variants[i] = temp; // wright variants
				}
				getline(fin, temp); // read right unswer
				q.right = temp; // write unswer to temp
				questions.push_back(q);
			}
		}
		fin.close();
	}
};


class App {
	Quiz quiz;
	
	//Player  player;
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;
	int counter;
	int AppMath()
	{
		system("cls");
		quiz.mathematics();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		//std::cout << player.userName << std::endl;
		for (int i = 0; i < quiz.questions.size(); ++i) {
			std::cout << "\t" << quiz.questions[i].content << std::endl;
			std::cout << std::endl;
			for (int j = 0; j < 4; ++j) {
				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "\tEnter your answer: ";
			std::cin >> choice;
			if (quiz.questions[i].variants[choice - 1] == quiz.questions[i].right) {
				++counter;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect";
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
			}
			else {
				std::cout << std::endl;
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "\tYour answer is    " << quiz.questions[i].variants[choice - 1] << std::endl;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
				std::cout << std::endl;
			}
		}
		if (counter > 3)
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "\tYour scor is " << counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\tYour scor is " << counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}

		return counter;
	}

	int AppPC() 
	{
		system("cls");
		quiz.PC();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		//std::cout << player.userName << std::endl;
		for (int i = 0; i < quiz.questions.size(); ++i) {
			std::cout << "\t" << quiz.questions[i].content << std::endl;
			std::cout << std::endl;
			for (int j = 0; j < 4; ++j) {
				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "\tEnter your answer: ";
			std::cin >> choice;
			if (quiz.questions[i].variants[choice - 1] == quiz.questions[i].right) {

				++counter;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect";
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
			}
			else {
				std::cout << std::endl;
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "\tYour answer is    " << quiz.questions[i].variants[choice - 1] << std::endl;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
				std::cout << std::endl;
			}
		}
		if (counter > 3)
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "\tYour scor is " << counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\tYour scor is " << counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);

		}
			return counter;
	}
};


class Player {
public:
	int score;
	std::string username, password;
	Player(std::string username,std::string password, int score = 0) {
		this->username = username;
		this->password = password;
		this->score = score;
	}
};

class Manager {
public:
	std::vector<Player> users;
	int current;
	//------------------------------------Constructor------------------------------------------------------
	Manager() {
		std::ifstream fin("players.txt"); //  in constructor, write from file
		while (!fin.eof()) {
			int score;
			std::string username, password;
			fin >> username >> password >> score;
			users.push_back(Player(username, password, score));
		}
		fin.close();
		current = -1;
	}
	//-------------------------------------Destructor----------------------------------------------------------
	~Manager() {
		std::ofstream fout("players.txt"); //  in destructor, get in to file
		for (int i = 0; i < users.size(); ++i) {
			fout << users[i].username << ' ' << users[i].password << ' ' << users[i].score << std::endl;
		}
		fout.close();
	}
	//-------------------------------------Registration--------------------------------------------------------
	void reg(std::string username, std::string password) { // registration
		users.push_back(Player(username, password));
	}
	//----------------------------------------login------------------------------------------------------------
	void login(std::string username,std::string password) { // login
		for (int i = 0; i < users.size(); ++i) {
			if (users[i].username == username && users[i].password == password) {
				current = i;
			}
		}
	}
};

/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class User {
public:
	int score;
	string username, password;
	User(string username, string password, int score = 0) {
		this->username = username;
		this->password = password;
		this->score = score;
	}
};

class Manager {
public:
	vector<User> users;
	int current;
	Manager() {
		ifstream fin("players.txt");
		while (!fin.eof()) {
			int score;
			string username, password;
			fin >> username >> password >> score;
			users.push_back(User(username, password, score));
		}
		fin.close();
		current = -1;
	}
	~Manager() {
		ofstream fout("players.txt");
		for (int i = 0; i < users.size(); ++i) {
			fout << users[i].username << ' ' << users[i].password << ' ' << users[i].score << endl;
		}
		fout.close();
	}
	void reg(string username, string password) {
		users.push_back(User(username, password));
	}
	void login(string username, string password) {
		for (int i = 0; i < users.size(); ++i) {
			if (users[i].username == username && users[i].password == password) {
				current = i;
			}
		}
	}
};

class Surrounding {
public:
	Manager * manager;
	Surrounding() {
		cout << "beginning" << endl;
		manager = new Manager();
	}
	~Surrounding() {
		cout << "ending" << endl;
		delete manager;
	}
	void greeting() {
		while (true) {
			cout << "hello! 1 for registration, 2 to for authorization, 3 for changing score, 4 for exit: " << endl;
			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
				reg();
				break;
			case 2:
				login();
				break;
			case 3:
				changeScore();
				break;
			case 4:
				return;
			default:
				break;
			}
		}
	}
	void reg() {
		string username, password;
		cout << "username and password: ";
		cin >> username >> password;
		manager->reg(username, password);
		login();
	}

	void login() {
		string username, password;
		cout << "username and password: ";
		cin >> username >> password;
		manager->login(username, password);
	}
	void changeScore() {
		++manager->users[manager->current].score;
	}
};


int main() {
	Surrounding s;
	s.greeting();
	return 0;
}
*/




int main()
{
    return 0;
}

