#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <Windows.h>

#include "Student.h"
#include "Group.h"
#include "Dean.h"

using namespace std;

vector<string> split( string s, char delimiter) {
	vector <string> tokens;
	string token;
	stringstream tokenStream;
	tokenStream << s;
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}
int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_CTYPE, "rus");
	srand(time(0));
	Dean IMIKN{ "IMIKN" };
	fstream in("studentsData.txt");
	fstream inGroups("groupsNames.txt");
	string info;

	vector<string> groups;
	while (getline(inGroups, info)) {
		vector<string> group = split(info, ' ');
		IMIKN.createGroup(group[0], group[1]);
		groups.push_back(group[0]);
	}

	while (getline(in, info)) {
		vector<string> student = split(info, ':');
		IMIKN.addStudentToGroup(student[0], student[1]);
		for (int i = 0; i < 10; i++) {
			IMIKN.addMarkToStudent(student[0], student[1], rand() % 10 + 1);
		}
	}

	for (auto& group : groups) {
		IMIKN.chooseMonitorInGroup(group);
	}
	cout << "Студенты зачислены на 1 семестр" << endl;
	cout << IMIKN;
	cout << endl << endl << endl;

	

	cout << "Смелоч Порфирий Михеевич переведен в " << IMIKN.trasferStudentToNewGroup("Смелоч Порфирий Михеевич", "18ПИ-2", "18ПМИ-2")->getGroupName();

	cout << endl << endl << endl;
	cout << "Прошла сессия" << endl;
	cout << "--------- процесс отчисления --------- " << endl;

	cout << "Отчислено " << IMIKN.expelStudentsByAverageMark(4) << " человек со средней оценкой ниже 4" << endl;
	
	for (auto& group : groups) {
		IMIKN.chooseMonitorInGroup(group);
	}
	cout << endl << endl << endl;

	cout << IMIKN;

	IMIKN.updateData("output.txt");
	return 0;

}