#include <iostream>
#include <string>
using namespace std;

// Abstraction
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    virtual void show() = 0; // pure virtual
};

// Inheritance
class Student : public Person
{
    double score; // Partial Encapsulation

public:
    // constructor (also calls base class)
    Student(string n, int a, double s) : Person(n, a)
    {
        score = s;
    }

    void show()
    { // Polymorphism
        string remark;

        if (score >= 90)
            remark = "Excellent";
        else if (score >= 75)
            remark = "Good";
        else if (score >= 60)
            remark = "Pass";
        else
            remark = "Fail";

        cout << name << " | Age:" << age
             << " | Score:" << score
             << " | " << remark << endl;
    }
};

int main()
{
    Student *list[10]; // using pointers to avoid default constructor issue
    int count = 0;

    int choice;
    string name;
    int age;
    double score;

    cout << "=== OOP Grade Tracker ===\n";

    while (true)
    {
        cout << "\n1.Add  2.View  0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0)
            break;

        if (choice == 1)
        {
            cout << "Name: ";
            getline(cin, name);

            cout << "Age: ";
            cin >> age;

            cout << "Score: ";
            cin >> score;
            cin.ignore();

            list[count++] = new Student(name, age, score);
        }
        else if (choice == 2)
        {
            for (int i = 0; i < count; i++)
            {
                list[i]->show();
            }
        }
    }

    cout << "Goodbye!\n";
}