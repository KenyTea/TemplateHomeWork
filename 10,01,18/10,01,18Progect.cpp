#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Player;
class Question;
class Quiz;

class Question {
public:
	string content;
	string variants[4];
	string right;
};

class Quiz {
public:
	std::string var;
	vector<Question> questions; // vector whith questions

	friend void retrieveQuestions() {
		ifstream fin("questions.txt"); // create file and read it
		if (!fin.is_open())  // check file
		{
			std::cout << "The file not found" << std::endl;
		}
		else if  (fin.is_open()) {
			string temp; // creat temp string
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
	int cnt = 0;
	int choice;
	Quiz quiz;
	
	quiz.retrieveQuestions();
	for (int i = 0; i < quiz.questions.size(); ++i) {
		std::cout << quiz.questions[i].content << std::endl;
		for (int j = 0; j < 4; ++j) {
			std::cout << quiz.questions[i].variants[j] << std::endl;
		}
		
		cin >> choice;
		if (quiz.questions[i].variants[choice - 1] == quiz.questions[i].right) {
			++cnt;
		}
		else {
			std::cout << "Your unswer is " << quiz.questions[i].variants[choice - 1] << std::endl;
			std::cout << "Right unswer is " << quiz.questions[i].right << std::endl;
		}
	}

};
int main() {
	setlocale(LC_ALL, "RU");
	
	
	
	system("pause");
	return 0;
}

	
		
		