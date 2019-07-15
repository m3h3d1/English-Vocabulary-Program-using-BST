#include<bits/stdc++.h>
using namespace std;

class Student {
private:
	string name, mail;
	int id;
	int tk;
public:
	Student(string name, string mail, int id);
	Student(string name, int id);
	void setName(string name);
	void setMail(string mail);
	void setID(int id);
	void print();
	void setMoney(int x) {
		tk = x;
	}
	string getName() { return name; }
	string getMail() { return mail; }
	int getID() { return id; }
	int getTK() { return tk; }
};
Student::Student(string name, string mail, int id) {
	this->name = name;
	this->mail = mail;
	this->id = id;
}
Student::Student(string name, int id) { 					//overloading
	this->name = name;
	this->id = id;
}
void Student::setName(string name) {
	this->name = name;
}
void Student::setMail(string mail) {
	this->mail = mail;
}
void Student::setID(int id) {
	this->id = id;
}
void Student::print() {
	cout<<"Name: "<<name<<'\n'
		<<"Email: "<<mail<<'\n'
		<<"ID: "<<id<<'\n';
}

class Scholar : public Student {
public:
	void show() {											//Function Overriding
		cout<<"Name: "<<getName()<<'\n'
			<<"Email: "<<getMail()<<'\n'
			<<"ID: "<<getID()<<'\n'
			<<"Scholarship: "<<getTK()<<'\n';
	}
};
int main() {
	Student xyz("xy", "xy@gmail.com", 101);
	xyz.print();
	cout<<endl;

	xyz.setName("xyz");
	xyz.setMail("xyz@gmail.com");
	xyz.setID(102);
	xyz.print();
	cout<<endl;

	Student A("A", 103);
	A.print();
	cout<<endl;

	//Scholar B;
	//Student &C = B;
	//Student B("B", "B@yahoo.com", 104);
	//B.setMoney(1000);
	//Scholar B;
	//B.print();
	Scholar b;
	b.Student("b",100);
	//b.show();

	Student &c = b;
	b.show();
	c.print();
	return 0;
}