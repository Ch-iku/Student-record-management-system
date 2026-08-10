#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }
};

vector<Student> students;

void addStudent() {
    int rollNo;
    string name;
    float marks;

    cout << "\nEnter Roll Number: ";
    cin >> rollNo;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    students.push_back(Student(rollNo, name, marks));

    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    for (const Student& s : students) {
        cout << "Roll No: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
        cout << "-----------------------\n";
    }
}

void searchStudent() {
    int rollNo;
    cout << "\nEnter Roll Number to search: ";
    cin >> rollNo;

    for (const Student& s : students) {
        if (s.rollNo == rollNo) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void saveToFile() {
    ofstream file("students.txt");

    for (const Student& s : students) {
        file << s.rollNo << "|" << s.name << "|" << s.marks << endl;
    }

    file.close();
}

void loadFromFile() {
    ifstream file("students.txt");

    if (!file) {
        return;
    }

    string roll, name, marks;

    while (getline(file, roll, '|') &&
           getline(file, name, '|') &&
           getline(file, marks)) {

        students.push_back(
            Student(stoi(roll), name, stof(marks))
        );
    }

    file.close();
}

int main() {

    loadFromFile();

    int choice;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                saveToFile();
                cout << "Records saved. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}