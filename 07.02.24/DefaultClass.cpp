#include <iostream>
#include"FileReader.h"
#include <Windows.h>
#include "Student.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Filereader fr;
	//Lines lines = fr.read("students.xml");
	//string* array = lines.getarray();
	//for (int i = 0; i < lines.getcountstring(); i++) {
	//	cout << array[i] << endl;
	//}
	FileReader fr;
	Lines lines = fr.read("students.xml");

	Student** student = new Student * [lines.getCountString()];
	for (int i = 0; i < lines.getCountString(); i++) {
		Lines line(lines.getArray()[i], ';');
		student[i] = new Student(line);
	}
	for (int i = 0; i < lines.getCountString(); i++) {
		student[i]->showInfo();
	}


}