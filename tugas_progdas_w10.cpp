#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_Student = 20;

struct studentType {
    string studentFirstName;
    string studentLastName;
    int testScore;
    char grade;
};

void readStudentData(studentType students[], int& numStudents) {
    cout << "Enter number of students (max " << MAX_Student << "): ";
    cin >> numStudents;
    cin.ignore();

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter first name of student " << (i + 1) << ": ";
        getline(cin, students[i].studentFirstName);
        cout << "Enter last name of student " << (i + 1) << ": ";
        getline(cin, students[i].studentLastName);
        cout << "Enter test score of student " << (i + 1) << ": ";
        cin >> students[i].testScore;
        cin.ignore();
    }
}

void assignGrades(studentType students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore >= 90)
            students[i].grade = 'A';
        else if (students[i].testScore >= 80)
            students[i].grade = 'B';
        else if (students[i].testScore >= 70)
            students[i].grade = 'C';
        else if (students[i].testScore >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

int findHighestScore(studentType students[], int numStudents) {
    int highest = students[0].testScore;
    for (int i = 1; i < numStudents; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
}

void displayStudentData(const studentType students[], int numStudents, int highestScore) {
    cout << fixed << setprecision(2);
    cout << "\nStudent Data:\n";
    cout << "-------------------------------\n";
    cout << "Name\t\tScore\tGrade\n";
    cout << "-------------------------------\n";

    for (int i = 0; i < numStudents; i++) {
        cout << students[i].studentLastName << " " << students[i].studentFirstName << "\t"
             << students[i].testScore << "\t" 
             << students[i].grade << "\n";
    }
    cout << "-------------------------------\n";
}

void printhighestscore (string firstName, string lastName, int highestScore) {
    cout << "\nHighest Score: " << highestScore << " by " << lastName << " " << firstName << "\n";
}
 int main() {
    studentType students[MAX_Student];
    int numStudents;

    readStudentData(students, numStudents);
    assignGrades(students, numStudents);
    int highestScore = findHighestScore(students, numStudents);

    string topFirstName, topLastName;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore == highestScore) {
            topFirstName = students[i].studentFirstName;
            topLastName = students[i].studentLastName;
            break; 
        }
    }

    displayStudentData(students, numStudents, highestScore);
    printhighestscore(topFirstName, topLastName, highestScore);

    return 0;
}
