#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
//using namespace std;
class Player;
class Question;
class Quiz;
class Menu;

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
		else   {
			std::string temp; // creat temp string
			while (!fin.eof()) {
				getline(fin, temp); //read first string 
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


class Player {
public:
	int counter = 0;
	int choice;
	std::string userName, checkName;
	std::string userPassword, userPassword1, userPassword2, CheckPass;
	int ctr = 0;
	
	void Registration() {
		std::string path;
		std::ofstream fout("Player.txt"); // create ofstream for rec
		fout.open(path, std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
		if (!fout.is_open()) { // проверка на открытия файла
			std::cout << "The file not found" << std::endl;
		}
		else { // посылаем в fout данные
			std::cout << "-----------Welcome to the QUIZ APP-----------" << std::endl;
			std::system("pause");
			std::system("cls");
			std::cout << "-----------REGOSTRATION-----------" << std::endl;
			std::cout << "Please, enter your user name ";
			std::cin >> userName;
			std::system("cls");
			std::cout << std::endl;
			std::cout << "Please, enter Your password ";
			std::cin >> userPassword1;
			std::system("cls");
			std::cout << std::endl;
			std::cout << "Please, enter password again ";
			std::cin >> userPassword2;

			if (userPassword1 == userPassword2)
			{
				userPassword = userPassword2;
				std::cout << "The password is correct";
			}
			else std::cout << "The password is incorrect"; return;

			std::cout << std::endl;
			fout << userName;
			fout << userPassword;
		}
		fout.close(); // close file !!!
		system("pause");
	}
};

class CheckUser {
	Player player;
public:
	std::vector <Player> usser;
	void Enter()
	{

		std::ifstream fin("Player.txt");
		if (fin.is_open()) {
			std::string u;

			while (!fin.eof()) {
				fin >> u; //name
				player.userName = u;
				fin >> u; //password
				player.userPassword = u;
				usser.push_back(player);
			}
		std::cout << "-----------Welcome to the QUIZ APP-----------" << std::endl;
		std::cout << std::endl;
		std::cout << "Please, enter your name ";
		std::cin >> player.checkName;
			std::system("cls");
		std::cout << std::endl;
		std::cout << "Please, enter password ";
		std::cin >> player.CheckPass;
		if (player.checkName == player.userName && player.CheckPass == player.userPassword) {
			std::cout << "Welcom to QUIZ APP mr' " << player.userName << std::endl;
		}
	}


};

class App {
	Quiz quiz;
	Player player;
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	void AppMath() {
		system("cls");
		quiz.mathematics();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		std::cout << player.name << std::endl;
		for (int i = 0; i < quiz.questions.size(); ++i) {
			std::cout << "\t" << quiz.questions[i].content << std::endl;
			std::cout << std::endl;
			for (int j = 0; j < 4; ++j) {
				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "\tEnter your answer: ";
			std::cin >> player.choice;
			if (quiz.questions[i].variants[player.choice - 1] == quiz.questions[i].right) {
				++player.counter;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect";
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
			}
			else {
				std::cout << std::endl;
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "\tYour answer is    " << quiz.questions[i].variants[player.choice - 1] << std::endl;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls"); 
				std::cout << std::endl;
			}
		}
		if (player.counter > 5) 
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "\tYour scor is " << player.counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else 
			SetConsoleTextAttribute(hConsole, 12);
		std::cout << "\tYour scor is " << player.counter << std::endl;
		    SetConsoleTextAttribute(hConsole, 7);


	}

	void AppPC() {
		system("cls");
		quiz.PC();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		std::cout << player.name << std::endl;
		for (int i = 0; i < quiz.questions.size(); ++i) {
			std::cout << "\t" << quiz.questions[i].content << std::endl;
			std::cout << std::endl;
			for (int j = 0; j < 4; ++j) {
				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "\tEnter your answer: ";
			std::cin >> player.choice;
			if (quiz.questions[i].variants[player.choice - 1] == quiz.questions[i].right) {
				++player.counter;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect";
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
			}
			else {
				std::cout << std::endl;
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "\tYour answer is    " << quiz.questions[i].variants[player.choice - 1] << std::endl;
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
				SetConsoleTextAttribute(hConsole, 7);
				_getch();
				system("cls");
				std::cout << std::endl;
			}
		}
		if (player.counter > 5)
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "\tYour scor is " << player.counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
			SetConsoleTextAttribute(hConsole, 12);
		std::cout << "\tYour scor is " << player.counter << std::endl;
		SetConsoleTextAttribute(hConsole, 7);


	}
};

class Menu {
	App app;
	Player player;
	Quiz quiz;
	int var;
public:
	void menu1() {
		
		system("cls");
		std::cout << "----------------Menu--------------------" << std::endl;
		std::cout << "If you want to pass a math test, enter 1" << std::endl;
		std::cout << "If you want to pass a PC test, enter 2" << std::endl;
		std::cout << "For EXIT, enter 0" << std::endl;
		std::cout << std::endl;
		std::cin >> var;
		
		while (true)
		{
			switch (var) {
			case 1: app.AppMath(); break;
			case 2: app.AppPC(); break;
			case 0: return;
			}
			
		}

}


};

int main() {
	
	Menu menu;
	menu.menu1();
	
	
	system("pause");
	return 0;
}

	
		
		