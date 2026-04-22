#include <iostream>
#include <string>
#include <fstream> // file handling
using namespace std;

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

    virtual void show() = 0;
};

class Student : public Person
{
    double score;

public:
    Student(string n, int a, double s) : Person(n, a)
    {
        score = s;
    }

    void show()
    {
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

    // NEW: write student to file
    void saveToFile(ofstream &file)
    {
        file << name << "," << age << "," << score << endl;
    }
};

int main()
{
    Student *list[10];
    int count = 0;

    string name;
    int age;
    double score;
    int choice;

    // load data from existing file
    ifstream inFile("students.txt");
    if (inFile)
    {
        while (getline(inFile, name, ','))
        {
            inFile >> age;
            inFile.ignore(); // skip comma
            inFile >> score;
            inFile.ignore(); // skip newline

            list[count++] = new Student(name, age, score);
        }
        inFile.close();
    }

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

            // create object
            list[count] = new Student(name, age, score);

            // append mode to save
            ofstream outFile("students.txt", ios::app);
            list[count]->saveToFile(outFile);
            outFile.close();

            count++;
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