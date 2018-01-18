#include "stdafx.h"

//class Question;
//class Quiz;
//class Player;
//class CheckUser;
//class Menu;
//
//enum ConsoleColor
//{
//	Black = 0,
//	Blue = 1,
//	Green = 2,
//	Cyan = 3,
//	Red = 4,
//	Magenta = 5,
//	Brown = 6,
//	LightGray = 7,
//	DarkGray = 8,
//	LightBlue = 9,
//	LightGreen = 10,
//	LightCyan = 11,
//	LightRed = 12,
//	LightMagenta = 13,
//	Yellow = 14,
//	White = 15
//};
//
//class Question // class for keep questtions, variants & correct answer
//{
//public:
//	std::string content;
//	std::string variants[4];
//	std::string right;
//};
//
//class Quiz
//{
//
//public:
//
//	std::vector<Question> questions; // vector whith questions
//
//	void mathematics() {
//		std::ifstream fin("mathematics.txt"); // create file and read it
//		if (!fin.is_open())  // check file
//		{
//			std::cout << "The file not found" << std::endl;
//		}
//		else {
//			std::string temp; // creat temp string
//			while (!fin.eof()) {
//				getline(fin, temp); //read first string 
//				if (temp == "") {
//					break;
//				}
//				Question q; // creat Question's object
//				q.content = temp; // write the read string to the created variable for the question
//
//				for (int i = 0; i < 4; ++i) {
//					getline(fin, temp); // read variants 
//					q.variants[i] = temp; // wright variants
//				}
//				getline(fin, temp); // read right unswer
//				q.right = temp; // write unswer to temp
//				questions.push_back(q);
//			}
//		}
//		fin.close();
//	}
//
//	void PC()
//	{
//		std::ifstream fin("PC.txt"); // create file and read it
//		if (!fin.is_open())  // check file
//		{
//			std::cout << "The file not found" << std::endl;
//		}
//		else {
//			std::string temp; // creat temp string
//			while (!fin.eof()) {
//				getline(fin, temp); //read first string 
//				if (temp == "") {
//					break;
//				}
//				Question q; // creat Question's object
//				q.content = temp; // write the read string to the created variable for the question
//
//				for (int i = 0; i < 4; ++i) {
//					getline(fin, temp); // read variants 
//					q.variants[i] = temp; // wright variants
//				}
//				getline(fin, temp); // read right unswer
//				q.right = temp; // write unswer to temp
//				questions.push_back(q);
//			}
//		}
//		fin.close();
//	}
//};
//
//
//class Player {
//
//public:
//	int counter = 0;
//	int choice;
//	std::string userName, checkName;
//	std::string userPassword, userPassword1, userPassword2, CheckPass;
//	int ctr = 0;
//	static Player & getInstace() {
//		static Player instance;
//		return instance;
//	}
//	/*void setCounter(int counter) { this->counter = counter; }
//	void setChoice(int choice) { this->choice = choice; }
//	void setUserName(std::string userName) { this->userName = userName; }
//	void setCheckName(std::string checkName) { this->checkName = checkName; }
//	void setUserPasswords(std::string userPassword) { this->userPassword = userPassword; }
//	void setUserPasswords1(std::string userPassword1) { this->userPassword1 = userPassword1; }
//	void setUserPasswords2(std::string userPassword2) { this->userPassword2 = userPassword2; }
//	void setCheckPass(std::string CheckPass) { this->CheckPass = CheckPass; }
//	void setCtr(int ctr) { this->ctr = ctr; }
//
//	int getCounter() { return counter; }
//	int getChoice() { return choice; }
//	std::string getUserName () { return userName; }
//	std::string getCheckName() { return checkName; }
//	std::string getUserPasswords() { return userPassword; }
//	std::string getUserPasswords1() { return userPassword1; }
//	std::string getUserPasswords2() { return userPassword2; }
//	std::string getCheckPas() { return CheckPass; }
//	int getCtr() { return ctr; }
//	*/
//
//
//
//};
//
//
//class App {
//	Quiz quiz;
//	Player & player = Player::getInstace();
//	//Player  player;
//public:
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	int AppMath()
//	{
//		system("cls");
//		quiz.mathematics();
//		SetConsoleTextAttribute(hConsole, 3);
//		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
//		SetConsoleTextAttribute(hConsole, 7);
//		std::cout << std::endl;
//		std::cout << player.userName << std::endl;
//		for (int i = 0; i < quiz.questions.size(); ++i) {
//			std::cout << "\t" << quiz.questions[i].content << std::endl;
//			std::cout << std::endl;
//			for (int j = 0; j < 4; ++j) {
//				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
//			}
//			std::cout << std::endl;
//			std::cout << "\tEnter your answer: ";
//			std::cin >> player.choice;
//			if (quiz.questions[i].variants[player.choice - 1] == quiz.questions[i].right) {
//				++player.counter;
//				SetConsoleTextAttribute(hConsole, 2);
//				std::cout << "\tCorrect";
//				SetConsoleTextAttribute(hConsole, 7);
//				_getch();
//				system("cls");
//			}
//			else {
//				std::cout << std::endl;
//				SetConsoleTextAttribute(hConsole, 12);
//				std::cout << "\tYour answer is    " << quiz.questions[i].variants[player.choice - 1] << std::endl;
//				SetConsoleTextAttribute(hConsole, 2);
//				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
//				SetConsoleTextAttribute(hConsole, 7);
//				_getch();
//				system("cls");
//				std::cout << std::endl;
//			}
//		}
//		if (player.counter > 3)
//		{
//			SetConsoleTextAttribute(hConsole, 2);
//			std::cout << "User " << player.checkName << "\tYour scor is " << player.counter << std::endl;
//			SetConsoleTextAttribute(hConsole, 7);
//		}
//		else
//		{
//			SetConsoleTextAttribute(hConsole, 12);
//			std::cout << "User " << player.checkName << "\tYour scor is " << player.counter << std::endl;
//			SetConsoleTextAttribute(hConsole, 7);
//		}
//
//		return player.counter;
//	}
//
//	int AppPC() {
//		system("cls");
//		quiz.PC();
//		SetConsoleTextAttribute(hConsole, 3);
//		std::cout << "\tHelp\tEnter the variant number!!!" << std::endl;
//		SetConsoleTextAttribute(hConsole, 7);
//		std::cout << std::endl;
//		std::cout << player.userName << std::endl;
//		for (int i = 0; i < quiz.questions.size(); ++i) {
//			std::cout << "\t" << quiz.questions[i].content << std::endl;
//			std::cout << std::endl;
//			for (int j = 0; j < 4; ++j) {
//				std::cout << "\t" << quiz.questions[i].variants[j] << std::endl;
//			}
//			std::cout << std::endl;
//			std::cout << "\tEnter your answer: ";
//			std::cin >> player.choice;
//			if (quiz.questions[i].variants[player.choice - 1] == quiz.questions[i].right) {
//				
//				++player.counter;
//				SetConsoleTextAttribute(hConsole, 2);
//				std::cout << "\tCorrect";
//				SetConsoleTextAttribute(hConsole, 7);
//				_getch();
//				system("cls");
//			}
//			else {
//				std::cout << std::endl;
//				SetConsoleTextAttribute(hConsole, 12);
//				std::cout << "\tYour answer is    " << quiz.questions[i].variants[player.choice - 1] << std::endl;
//				SetConsoleTextAttribute(hConsole, 2);
//				std::cout << "\tCorrect answer is " << quiz.questions[i].right << std::endl;
//				SetConsoleTextAttribute(hConsole, 7);
//				_getch();
//				system("cls");
//				std::cout << std::endl;
//			}
//		}
//		if (player.counter > 3)
//		{
//			SetConsoleTextAttribute(hConsole, 2);
//			std::cout << "\tYour scor is " << player.counter << std::endl;
//			SetConsoleTextAttribute(hConsole, 7);
//		}
//		else
//		{
//			SetConsoleTextAttribute(hConsole, 12);
//			std::cout << "\tYour scor is " << player.counter << std::endl;
//			SetConsoleTextAttribute(hConsole, 7);
//			
//			return player.counter;
//		}
//	}
//};
//
////_____________________________________________________________________________________
//class CheckUser
//{
//public:
//	//Player player;
//	Player & player = Player::getInstace();
//	App app; 
//	std::vector <Player> usser;
//	
//
//	void retrieveUsers() {
//		std::ifstream fin("Player.txt");
//		if (fin.is_open()) {
//
//			while (!fin.eof()) 
//			{		
//				fin >> player.userName >> player.userPassword >> player.counter;
//					usser.push_back(player);
//			}
//			fin.close();
//		}
//	}
//
//
//	bool SaveUseres() 
//	{
//		std::ofstream fout;
//
//		fout.open("Player.txt"); // Add , std::ofstream::app , for add to (don't clear)
//
//		if (fout.is_open()) 
//		{
//
//			for (int i = 0; i < usser.size(); i++) 
//			{
//				fout  << usser.at(i).userName << "\n" << usser.at(i).userPassword << "\n"
//					<< usser.at(i).counter << "\n";
//			}
//		
//			fout.close();
//		}
//		else return false;
//
//		return true;
//	}
//	
//	
//	void PlayerInfo()
//	{
//		system("cls");
//		
//		for (int i = 0; i <usser.size(); i++)
//			std::cout << "User " << usser.at(i).userName << " | " << "Scor " << usser.at(i).counter << "\n";
//
//	}
//
//	void Registration()
//	{
//		Player temp;
//		system("cls");
//		std::cout << "\t-----------REGISTRATION-----------" << std::endl;
//		std::cout << "\tPlease, enter your user name ";
//		std::cin >> temp.userName;
//		std::system("cls");
//		std::cout << std::endl;
//		std::cout << "\tPlease, enter Your password ";
//		std::cin >> temp.userPassword1;
//		std::system("cls");
//		std::cout << std::endl;
//		std::cout << "\tPlease, enter password again ";
//		std::cin >> temp.userPassword2;
//
//		if (temp.userPassword1 == temp.userPassword2)
//		{
//			temp.userPassword = temp.userPassword2;
//			std::cout << "\tThe password is correct" << std::endl;
//			temp.counter = 0;
//			system("cls");
//			std::cout << std::endl;
//			std::cout << "Created new User "<< std::endl;
//			std::cout << std::endl;
//			std::cout << "User Name " << temp.userName << " | " << "User Password " << temp.userPassword << " | " << "User Scor " << temp.counter; _getch();
//
//			usser.push_back(temp);
//			
//			system("pause");
//			system("cls");
//
//			menuForQuiz();
//			
//		}
//		else std::cout << "\tThe password is incorrect"; system("pause"); return;
//
//	}
//	void menuForQuiz()
//	{
//		system("cls");
//		int var;
//		while (true)
//		{
//			std::cout << std::endl;
//			std::cout << "\t-----------------Menu--------------------" << std::endl;
//			std::cout << "\tIf You whant to show scor, enter 1" << std::endl;
//			std::cout << "\tIf you want to pass a math test, enter 2" << std::endl;
//			std::cout << "\tIf you want to pass a PC test, enter 3" << std::endl;
//			std::cout << "\tFor EXIT, enter 0" << std::endl;
//			std::cout << std::endl;
//			std::cin >> var;
//			
//			switch (var) {
//			case 1: PlayerInfo(); break;
//			case 2: player.counter = app.AppMath(); break;
//			case 3: player.counter = app.AppPC(); break;
//			case 0: SaveUseres(); exit(0);
//			}
//		}
//	}
//	};
//
////_____________________________________________________________________________________
//
//
//class Menu : public CheckUser
//{
//public:
//	//Player  player;
//	Player & player = Player::getInstace();
//	Quiz quiz;
//	CheckUser  user;
//	
//	int var;
//	void menuRegOrEnter()
//	{
//		user.retrieveUsers();
//		
//		while (true)
//		{
//		system("cls");
//		std::cout << std::endl;
//		std::cout << "\t---------------Welcome to the QUIZ APP---------------" << std::endl;
//		std::cout << std::endl;
//		std::cout << "\t        If You have Account, please enter 1" << std::endl;
//		std::cout << std::endl;
//		std::cout << "\t         For registratoin, please enter 2" << std::endl;
//		std::cout << std::endl;
//		std::cout << "\t                 For EXIT, enter 0" << std::endl;
//		std::cout << std::endl;
//		std::cin >> var;
//			switch (var) {
//			case 1: Enter(); break;
//			case 2: user.Registration(); break;
//			case 0: user.usser.push_back(player); user.SaveUseres(); return;
//			}
//		}
//	}
//	
//	void Enter()
//	{
//		system("cls");
//		std::cout << "\t-------------AUTHORIZATION-------------" << std::endl;
//		std::cout << std::endl;
//		std::cout << "\t        Please, enter your name ";
//		std::cin >> player.checkName;
//		std::system("cls");
//		std::cout << "\t-------------AUTHORIZATION-------------" << std::endl;
//		std::cout << std::endl;
//		std::cout << "\t         Please, enter password ";
//		std::cin >> player.CheckPass;
//		
//
//		for (int i = 0; i < user.usser.size(); i++)
//		{
//			if (player.ctr <= 3)
//			{
//				if (player.checkName == user.usser.at(i).userName && player.CheckPass == user.usser.at(i).userPassword)
//				{
//					std::system("cls");
//					std::cout << std::endl;
//					std::cout << "\t  Welcom to QUIZ APP mr' " << player.checkName << std::endl;
//					system("pause");
//					//-------------------------------------------------------------------------
//					player.userName = player.checkName = user.usser.at(i).userName;
//					player.counter = user.usser.at(i).counter;
//					//-------------------------------------------------------------------------
//
//					user.menuForQuiz();
//				}
//				else
//				{
//					system("cls");
//					std::cout << std::endl;
//					std::cout << "\t     User not found ";
//					_getch();
//					menuRegOrEnter();
//				}
//			}
//			else user.Registration();
//		}
//		//std::ifstream fin("Player.txt");
//		//if (!fin.is_open())  // check file
//		//{
//		//	std::cout << "\tThe file not found" << std::endl;
//		//}
//		//else
//		//{
//		//	std::string temp; // creat temp string
//		//	while (!fin.eof())
//		//	{
//		//		getline(fin, temp);
//		//		player.userName = temp; //name
//		//		getline(fin, temp);
//		//		player.userPassword = temp; // password
//		//		usser.push_back(player);
//		//		if (player.ctr <= 3)
//		//		{
//		//			if (player.checkName == player.userName && player.CheckPass == player.userPassword)
//		//			{
//		//				std::system("cls");
//		//				std::cout << std::endl;
//		//				std::cout << "\t  Welcom to QUIZ APP mr' " << player.userName << std::endl;
//		//				system("pause");
//		//				system("cls");
//		//				user.menuForQuiz();
//		//			}
//		//			else
//		//			{
//		//				system("cls");
//		//				std::cout << std::endl;
//		//				std::cout << "\t     User not found ";
//		//				_getch();
//		//				menuRegOrEnter();
//		//			}
//		//		}
//		//		else
//		//		{
//		//			user.Registration();
//		//		}
//		//	}
//		//}
//	}
//};
//
//static int ID = 0;
//
//int main()
//{
//	Menu menu;
//	menu.menuRegOrEnter();
//	/*CheckUser u;
//	u.retrieveUsers();*/
//	system("pause");
//	return 0;
//}

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

class CheckUsers {
public:
	vector<User> users;
	int current;
	CheckUsers() {
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
	~CheckUsers() {
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

class Menu {
public:
	CheckUsers * _user;
	Menu() {
		cout << "beginning" << endl;
		_user = new CheckUsers();
	}
	~Menu() {
		cout << "ending" << endl;
		delete _user;
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
		_user->reg(username, password);
		login();
	}

	void login() {
		string username, password;
		cout << "username and password: ";
		cin >> username >> password;
		_user->login(username, password);
	}
	void changeScore() {
		++_user->users[_user->current].score;
	}
};


int main() {
	Menu s;
	s.greeting();
	return 0;
}
