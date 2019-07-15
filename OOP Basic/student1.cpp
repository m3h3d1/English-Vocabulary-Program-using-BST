#include<bits/stdc++.h>
using namespace std;

class Student {                                              //Encapsulation
private:                                                     //Abstraction
    string name, mail;
    int id;
public:
    Student() {                                              //constructor
        id = 0;
    }
    Student(string name, int id, string mail) {             //Overloading
        this->name = name;
        this->id = id;
        this->mail = mail;
    }
    void basic();
    //void setName(string name);
    //void setMail(string mail);
    //void setID(int id);
    void print();
    void check() {
        cout<<"This is student class\n";
    }
};
void Student::basic() {
    cout<<"Input Basic Info: ";
    cin>>name;
    cin>>mail;
    cin>>id;
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
        <<"ID: "<<id<<'\n'
        <<"Email: "<<mail<<'\n';
}

class Result: public Student {                              //Inheritence
private:
    int total;
    double perc;
public:
    void getResult();
    void putResult();
    void check() {                                          //polymorphism/ Overriding
        cout<<"This is Result class\n";
    }
};
void Result:: getResult() {
    cout<<"Enter Total Number: "; 
    cin>>total;
    perc = (double) (total*100/500); //number of subject 5
}
void Result:: putResult() {
    cout<<"Total Marks: "<<total<<'\n'
        <<"Percentage: "<<perc<<'\n';
}

int main() {
    Student A;                                             //Object
    A.check();
    cout<<endl;

    Result B;
    B.check();
    B.basic();
    B.print();
    B.getResult();
    B.putResult();
    cout<<endl;

    Student C("C", 102, "C@gmail.com");
    //C.setName("CC");
    C.print();
    return 0;
}



/*
ABC ABC@gmail.com 101
400



*/