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


class Player {
public:
	int counter = 0;
	int choice;
	std::string userName, checkName;
	std::string userPassword, userPassword1, userPassword2, CheckPass;
	int ctr = 0;
};

class App {
	Quiz quiz;
	Player  player;
	//CheckUser user;
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int AppMath()
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

			//std::ofstream fout; // create ofstream for rec
			//fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
			//if (!fout.is_open())
			//{ // проверка на открытия файла
			//	std::cout << "The file not found" << std::endl;
			//}
			//else
			//{
			//	fout << player.userName << std::endl;
			//	fout << player.userPassword << std::endl;
			//	fout << player.counter;
			//}

			//fout.close();
		}
		//user.AddPlayerToFile(player.userName, player.userPassword, player.counter);

		return player.counter;
	}

	int AppPC() {
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
			//coment Alfara********************************************************

			//std::ofstream fout; // create ofstream for rec
			//fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
			//if (!fout.is_open())
			//{ // проверка на открытия файла
			//	std::cout << "The file not found" << std::endl;
			//}
			//else
			//{
			//	fout << player.userName << std::endl;
			//	fout << player.userPassword << std::endl;
			//	fout << player.counter;
			//}

			//fout.close();
			//}

			//coment Alfara********************************************************
			return player.counter;
			//user.AddPlayerToFile(player.userName, player.userPassword, player.counter);
		}
	}
};

//_____________________________________________________________________________________
class CheckUser
{
public:
	Player player;
	App app; //sozdal Alfar
	//*****************************************

	//*****************************************
	//void AddPlayerToFile(std::string n, std::string p, int c)
	//{
	//	std::ofstream fout; // create ofstream for rec
	//	fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
	//	if (!fout.is_open())
	//	{ // проверка на открытия файла
	//		std::cout << "The file not found" << std::endl;
	//	}
	//	else
	//	{
	//		fout << n << std::endl;
	//		fout << p << std::endl;
	//		fout << c << std::endl;
	//	}
	//	fout.close();
	//}
//*****************************************

//***********************************************************************
	void retrieveUsers() {
		std::ifstream fin("Player.txt");
		if (fin.is_open()) {
			std::string s;

			while (!fin.eof()) {
				/*	fin >> s; //name
				temp.nameUser = s;
				fin >> s; //password
				temp.pass = s;
				fin >> temp.is_new_user >> temp.rate; //new or old user and rating
				usersss.push_back(temp);*/

				fin >> player.userName >> player.userPassword >> player.counter;
				//if (!(player.userName == "1000000000" || player.userPassword == "1000000000"))
					usser.push_back(player);
			//	player.userName = "1000000000";
			//	player.userPassword == "1000000000";
			}
			fin.close();
		}
	}

	//***********************************************************************

	bool SaveUseres() 
	{
		std::ofstream fout;

		fout.open("Player.txt"); // Add , std::ofstream::app , for add to (don't clear)

		if (fout.is_open()) 
		{

			for (int i = 0; i < usser.size(); i++) 
			{
				fout << usser.at(i).userName << "\n" << usser.at(i).userPassword << "\n"
					<< usser.at(i).counter << "\n";
				/*fout << usser.at(i).userName << std::endl;
				fout << usser.at(i).userPassword << std::endl;
				fout << usser.at(i).counter;*/
			}
			fout.close();
		}
		else return false;

		return true;
	}
	
	std::vector <Player> usser;
	
	void PlayerInfo()
	{
		system("cls");

		for (int i = 0; i <usser.size(); i++)
			std::cout << "User " << usser.at(i).userName << " | " << "Scor " << usser.at(i).counter << "\n";

		/******************************************************

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
				usser.push_back(player);
			}
			std::cout << "User " << player.userName << " | ";
			int ss;
			while (!fin.eof())
			{
				fin >> ss;
				player.counter = ss;
			}
			std::cout << "Score " << player.counter << std::endl;
		}

		***************************************************/
	}

	void Registration()
	{
		Player temp;
		system("cls");
		std::cout << "\t-----------REGOSTRATION-----------" << std::endl;
		std::cout << "\tPlease, enter your user name ";
		std::cin >> temp.userName;
		std::system("cls");
		std::cout << std::endl;
		std::cout << "\tPlease, enter Your password ";
		std::cin >> temp.userPassword1;
		std::system("cls");
		std::cout << std::endl;
		std::cout << "\tPlease, enter password again ";
		std::cin >> temp.userPassword2;

		if (temp.userPassword1 == temp.userPassword2)
		{
			temp.userPassword = temp.userPassword2;
			std::cout << "\tThe password is correct" << std::endl;
			temp.counter = 0;
			system("cls");
			//user.AddPlayerToFile(player.userName, player.userPassword, player.counter);
			std::cout << std::endl;
			std::cout << "Created new User "<< std::endl;
			std::cout << std::endl;
			std::cout << "User Name " << temp.userName << " | " << "User Password " << temp.userPassword << " | " << "User Scor " << temp.counter; _getch();

			// Test++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			//SaveUseres();
			// Test++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


			//coment Alfara********************************************************

			//std::ofstream fout; // create ofstream for rec
			//fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
			//if (!fout.is_open())
			//{ // проверка на открытия файла
			//	std::cout << "The file not found" << std::endl;
			//}
			//else
			//{
			//	fout << player.userName << std::endl;
			//	fout << player.userPassword << std::endl;
			//	fout << player.counter << std::endl;
			//}

			//fout.close();

			//coment Alfara********************************************************
			
			retrieveUsers();
			usser.push_back(temp);

			//))))))))))))))))))))))))))))))))))))))))))))))))))
	        PlayerInfo(); _getch();
			//))))))))))))))))))))))))))))))))))))))))))))))))))
			
			system("pause");
			system("cls");
			//--------------------------------------------------------------------------------------
			//int var;
			//while (true)
			//{
			//	std::cout << std::endl;
			//	std::cout << "\t-----------------Menu--------------------" << std::endl;
			//	std::cout << "\tIf You whant to show scor, enter 1" << std::endl;
			//	std::cout << "\tIf you want to pass a math test, enter 2" << std::endl;
			//	std::cout << "\tIf you want to pass a PC test, enter 3" << std::endl;
			//	std::cout << "\tFor EXIT, enter 0" << std::endl;
			//	std::cout << std::endl;
			//	std::cin >> var;
			//	//system("cls");
			//	switch (var) {
			//	case 1: usser.push_back(player); SaveUseres(); PlayerInfo(); break;
			//	case 2: player.counter = app.AppMath(); break;
			//	case 3: player.counter = app.AppPC(); break;
			//	case 0: usser.push_back(player); SaveUseres(); return;
			//	}
			//}
			//----------------------------------------------------------------------------------------
			// zamenil na
			menuForQuiz();
			//----------------------------------------------------------------------------------------
			usser.push_back(player);
			SaveUseres();
			PlayerInfo();
			

		}
		else std::cout << "\tThe password is incorrect"; return;

	}
	void menuForQuiz()
	{
		int var;
		while (true)
		{
			std::cout << std::endl;
			std::cout << "\t-----------------Menu--------------------" << std::endl;
			std::cout << "\tIf You whant to show scor, enter 1" << std::endl;
			std::cout << "\tIf you want to pass a math test, enter 2" << std::endl;
			std::cout << "\tIf you want to pass a PC test, enter 3" << std::endl;
			std::cout << "\tFor EXIT, enter 0" << std::endl;
			std::cout << std::endl;
			std::cin >> var;
			
			switch (var) {
			case 1: usser.push_back(player); SaveUseres(); PlayerInfo(); break;
			case 2: player.counter = app.AppMath(); break;
			case 3: player.counter = app.AppPC(); break;
			case 0: usser.push_back(player); SaveUseres(); return;
			}
		}
	}
	};

//_____________________________________________________________________________________






class Menu 
{
	//App  app;
	Player  player;
	Quiz quiz;
	CheckUser  user;
	int var;
	
public:
	void menuRegOrEnter()
	{
		while (true)
		{
		system("cls");
		std::cout << std::endl;
		std::cout << "\t---------------Welcome to the QUIZ APP---------------" << std::endl;
		std::cout << std::endl;
		std::cout << "\t        If You have Account, please enter 1" << std::endl;
		std::cout << std::endl;
		std::cout << "\t         For registratoin, please enter 2" << std::endl;
		std::cout << std::endl;
		std::cout << "\t                 For EXIT, enter 0" << std::endl;
		std::cout << std::endl;
		std::cin >> var;
			switch (var) {
			case 1: Enter(); break;
			case 2: user.Registration(); break;
			case 0: user.usser.push_back(player); user.SaveUseres(); return;
			}

		}

	}
	


	void Enter()
	{
		system("cls");
		std::vector <Player> usser;
		std::cout << "\t-------------AUTHORIZATION-------------" << std::endl;
		std::cout << std::endl;
		std::cout << "\t        Please, enter your name ";
		std::cin >> player.checkName;
		std::system("cls");
		std::cout << "\t-------------AUTHORIZATION-------------" << std::endl;
		std::cout << std::endl;
		std::cout << "\t         Please, enter password ";
		std::cin >> player.CheckPass;
		std::ifstream fin("Player.txt");
		if (!fin.is_open())  // check file
		{
			std::cout << "\tThe file not found" << std::endl;
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
						std::system("cls");
						std::cout << std::endl;
						std::cout << "\t  Welcom to QUIZ APP mr' " << player.userName << std::endl;
						system("pause");
						system("cls");

						user.menuForQuiz();
					}
					else
					{
						system("cls");
						std::cout << std::endl;
						std::cout << "\t     User not found ";
						_getch();
						menuRegOrEnter();
					}
				}
				else
				{
					user.Registration();
				}
			}
		}
	}

	//void Registration()
	//{
	//	system("cls");
	//	std::cout << "\t-----------REGOSTRATION-----------" << std::endl;
	//	std::cout << "\tPlease, enter your user name ";
	//	std::cin >> player.userName;
	//	std::system("cls");
	//	std::cout << std::endl;
	//	std::cout << "\tPlease, enter Your password ";
	//	std::cin >> player.userPassword1;
	//	std::system("cls");
	//	std::cout << std::endl;
	//	std::cout << "\tPlease, enter password again ";
	//	std::cin >> player.userPassword2;

	//	if (player.userPassword1 == player.userPassword2)
	//	{
	//		player.userPassword = player.userPassword2;
	//		std::cout << "\tThe password is correct" << std::endl;

	//		//user.AddPlayerToFile(player.userName, player.userPassword, player.counter);

	//		std::ofstream fout; // create ofstream for rec
	//		fout.open("Player.txt", std::ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
	//		if (!fout.is_open())
	//		{ // проверка на открытия файла
	//			std::cout << "The file not found" << std::endl;
	//		}
	//		else
	//		{
	//			fout << player.userName << std::endl;
	//			fout << player.userPassword << std::endl;
	//			fout << player.counter << std::endl;
	//		}

	//		fout.close();
	//		menu1();

	//	}
	//	else std::cout << "\tThe password is incorrect"; return;
	//}

	//coment Alfara********************************************************

	//void menu1()
	//{
	//	while (true)
	//	{
	//		std::cout << "\t----------------Menu--------------------" << std::endl;
	//		std::cout << "\tIf You whant to show scor, enter 1" << std::endl;
	//		std::cout << "\tIf you want to pass a math test, enter 2" << std::endl;
	//		std::cout << "\tIf you want to pass a PC test, enter 3" << std::endl;
	//		std::cout << "\tFor EXIT, enter 0" << std::endl;
	//		std::cout << std::endl;
	//		std::cin >> var;
	//		//system("cls");
	//		switch (var) {
	//		case 1: user.PlayerInfo(); break;
	//		case 2: app.AppMath(); break;
	//		case 3: app.AppPC(); break;
	//		case 0: return;
	//		}
	//	}
	//}


	//coment Alfara********************************************************


};

int main()
{
	Menu menu;
	menu.menuRegOrEnter();
	system("pause");
	return 0;

	
	
}
