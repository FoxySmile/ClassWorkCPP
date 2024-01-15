#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
	int total = 0;
public:
	Fraction(int numerator, int denominator) {
		total = numerator / denominator;
		this->denominator = denominator;
		this->numerator = numerator % denominator;
	}

	void show() {
		if (total == 0) {
			cout << numerator << "/" << denominator << endl;
		}
		if (numerator % denominator == 0) {
			cout << total << endl;
		}
		else cout << total << " " << numerator << "/" << denominator << endl;
	}
};

class Student {
private:
	string name;
	int num;
	double bal;
public:
	Student(string name, int num, int bal) {
		this->name = name;
		this->num = num;
		this->bal = bal;
	}
	void show_all() {
		cout << "Student: " << name << ", " << "grupa " << num << ", " << "bal " << bal << endl;
	}

	string getStatus() {
		if (bal > 4.6) return "A";
		if (bal > 3.6) return "B";
		if (bal > 2.6) return "C";
		else return "D";
	}
};



int main() {
	/*Fraction f1(3, 6);
	f1.show();*/
	/*Student st1("Pol", 2, 4.5);
	st1.show_all();
	cout << "Status: " << st1.getStatus() << endl;*/

	Fraction f2(12, 4);
	f2.show();
}