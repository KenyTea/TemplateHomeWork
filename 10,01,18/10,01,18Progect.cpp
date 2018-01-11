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

enum ConsoleColor {
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

class Question {
public:
	std::string content;
	std::string variants[4];
	std::string right;
};

class Quiz {
	
public:
	std::string File(int temp) {
		std::string var;
		if (temp == 1)
		{
			var = "mathematics.txt";
			return var;
        }
		else if (temp == 2) 
		{
			var = "PC.txt";
			return var;
		}
	}
	std::vector<Question> questions; // vector whith questions
	
	void retrieveQuestions(int var) {
		std::ifstream fin(File(var)); // create file and read it
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
	}

	
};


class Player {
public:
	int counter = 0;
	int choice;
	std::string name;
	
};

class App {
	Quiz quiz;
	Player player;
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	void doApp(int var) {
		system("cls");
		quiz.retrieveQuestions(var);
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
		std::cout << "To pass the test, enter your name ";
		std::cin >> player.name;
		std::cout << std::endl;
		system("cls");
		while (true)
		{
			system("cls");
			std::cout << "----------------Menu--------------------" << std::endl;
			std::cout << "If you want to pass a math test, enter 1" << std::endl;
			std::cout << "If you want to pass a PC test, enter 2" << std::endl;
			std::cout << std::endl;
			std::cin >> var;
			app.doApp(var);
		}

}


};

int main() {
	
	Menu menu;
	menu.menu1();
	
	
	system("pause");
	return 0;
}

	
		
		