#include "stdafx.h"

class Question;
class Quiz;
class Player;
class CheckUser;
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
};

class CheckUser
{
	Player player;

public:
	
	void AddPlayerToFile(std::string n, std::string p, int c)
	{
		std::ofstream fout; // create ofstream for rec
		fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
		if (!fout.is_open())
		{ // проверка на открытия файла
			std::cout << "The file not found" << std::endl;
		}
		else
		{
			fout << n << std::endl;
			fout << p << std::endl;
			fout << c << std::endl;
			fout << std::endl;
		}

		fout.close();
	}

	void PlayerInfo() 
	{
		std::vector <Player> usser;
		
		std::ifstream fin("Player.txt");
		if (!fin.is_open())  // check file
		{
			std::cout << "The file not found" << std::endl;
		}
		else
		{
			std::string temp; // creat temp string
				
			while (!fin.eof())
			{
				getline(fin, temp);
				player.userName = temp; //name
				getline(fin, temp);
				/*player.counter = temp;
				usser.push_back(player);*/

			}
				std::cout << "User " << player.userName << " | ";
			while (!fin.eof())
			{
				fin >> player.counter;
			}
				std::cout << "Score " << player.counter << std::endl;

		}
	}
};

class App {
	Quiz quiz;
	Player player;
	CheckUser user;
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void AppMath()
	{
		system("cls");
		quiz.mathematics();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		std::cout << player.userName << std::endl;
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
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\tYour scor is " << player.counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		user.AddPlayerToFile(player.userName, player.userPassword, player.counter);
	}

	void AppPC() {
		system("cls");
		quiz.PC();
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
		std::cout << player.userName << std::endl;
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
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\tYour scor is " << player.counter << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		user.AddPlayerToFile(player.userName, player.userPassword, player.counter);
	}
};


class Menu
{
	App app;
	Player player;
	Quiz quiz;
	CheckUser user;
	int var;
public:
	void menuRegOrEnter()
	{
		std::cout << "-----------Welcome to the QUIZ APP-----------" << std::endl;
		std::cout << std::endl;
		std::cout << "If You have Account, pleas enter 1" << std::endl;
		std::cout << "For registratoin, pleas enter 2" << std::endl;
		std::cout << std::endl;
		std::cin >> var;
		while (true)
		{
			switch (var) {
			case 1: Enter(); break;
			case 2: Registration(); break;
			}

		}
	}

	

	void Enter()
	{
		std::vector <Player> usser;
		std::cout << "-----------Menu enter-----------" << std::endl;
		std::cout << std::endl;
		std::cout << "Please, enter your name ";
		std::cin >> player.checkName;
		std::system("cls");
		std::cout << std::endl;
		std::cout << "Please, enter password ";
		std::cin >> player.CheckPass;
		std::ifstream fin("Player.txt");
		if (!fin.is_open())  // check file
		{
			std::cout << "The file not found" << std::endl;
		}
		else
		{
			std::string temp; // creat temp string
			while (!fin.eof())
			{
				getline(fin, temp);
				player.userName = temp; //name
				getline(fin, temp);
				player.userPassword = temp; // password
				usser.push_back(player);
				if (player.ctr <= 3)
				{
					if (player.checkName == player.userName && player.CheckPass == player.userPassword)
					{
						std::cout << "Welcom to QUIZ APP mr' " << player.userName << std::endl;
						system("pause");
						system("cls");
						menu1();
					}
					else
					{
						std::cout << "User not found ";
						menuRegOrEnter();
					}
				}
				else
				{
					Registration();
				}
			}
		}
	}

	void Registration()
	{
		std::cout << "-----------REGOSTRATION-----------" << std::endl;
		std::cout << "Please, enter your user name ";
		std::cin >> player.userName;
		std::system("cls");
		std::cout << std::endl;
		std::cout << "Please, enter Your password ";
		std::cin >> player.userPassword1;
		std::system("cls");
		std::cout << std::endl;
		std::cout << "Please, enter password again ";
		std::cin >> player.userPassword2;

		if (player.userPassword1 == player.userPassword2)
		{
			player.userPassword = player.userPassword2;
			std::cout << "The password is correct" << std::endl;
			user.AddPlayerToFile(player.userName, player.userPassword, 0);
			menu1();

		}
		else std::cout << "The password is incorrect"; return;
	}

	void menu1()
	{
		system("cls");
		std::cout << "----------------Menu--------------------" << std::endl;
		std::cout << "If You whant to show scor, enter 1" << std::endl;
		std::cout << "If you want to pass a math test, enter 2" << std::endl;
		std::cout << "If you want to pass a PC test, enter 3" << std::endl;
		std::cout << "For EXIT, enter 0" << std::endl;
		std::cout << std::endl;
		std::cin >> var;

		while (true)
		{
			switch (var) {
			case 1: user.PlayerInfo(); break;
			case 2: app.AppMath(); break;
			case 3: app.AppPC(); break;
			case 0: return;
			}
		}
	}
};

int main()
{
	Menu menu;
	menu.menuRegOrEnter();
	//menu.menu1();


	system("pause");
	return 0;
}
