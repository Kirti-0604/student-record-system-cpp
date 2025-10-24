#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

Student students[100];  // store up to 100 students
int countStudents = 0;  // number of students currently stored

void addStudent() {
    cout << "\n=== Add Student Record ===\n";
    cout << "Enter Roll Number: ";
    cin >> students[countStudents].roll;
    cin.ignore();  // to clear newline from buffer
    cout << "Enter Name: ";
    getline(cin, students[countStudents].name);
    cout << "Enter Marks: ";
    cin >> students[countStudents].marks;
    countStudents++;
    cout << " Student added successfully!\n";
}

void displayStudents() {
    if (countStudents == 0) {
        cout << "\n No student records found!\n";
        return;
    }

    cout << "\n=== Student Records ===\n";
    cout << "Roll No.\tName\t\tMarks\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < countStudents; i++) {
        cout << students[i].roll << "\t\t" 
             << students[i].name << "\t\t" 
             << students[i].marks << "\n";
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].roll == roll) {
            cout << "\nRecord Found \n";
            cout << "Roll Number: " << students[i].roll << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }
    cout << " Record not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < countStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            countStudents--;
            cout << " Record deleted successfully!\n";
            return;
        }
    }
    cout << " Record not found!\n";
}

void menu() {
    cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        case 3: searchStudent(); break;
        case 4: deleteStudent(); break;
        case 5: cout << "\n Exiting program... Goodbye!\n"; break;
        default: cout << " Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
