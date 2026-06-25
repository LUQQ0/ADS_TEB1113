#include <iostream>
#include <string>
using namespace std;

struct Student{
    string id;
    string name;
    string course;
    int age;
};

int main() {
    
    Student student[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i+1 << endl;
        cout << "---------------------------" << endl;
        cout << "Enter name : " ;
        cin >> student[i].name;
        cout << "Enter id : " ;
        cin >> student[i].id;
        cout << "Enter course : " ;
        cin >> student[i].course;
        cout << "Enter age : " ;
        cin >> student[i].age;
        cout << "---------------------------" << endl;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i+1 << endl;
        cout << "---------------------------" << endl;
        cout << "Name : " << student[i].name << endl;
        cout << "ID : " << student[i].id << endl;
        cout << "Course : " << student[i].course << endl;
        cout << "Age : " << student[i].age << endl;
        cout << "---------------------------" << endl;
    }
    

    return 0;
}