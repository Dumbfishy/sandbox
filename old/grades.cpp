
#include <iostream>
#include <string>

using namespace std;

struct students {
    string name;
    int grade;
};

void sort(students *Student, int numStudents);

int main (void) 
{
    cout << "How many students do you have?: ";
    int numStudents;
    cin >> numStudents;

    students Students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the #" << i+1 << " students name:";
        cin >> Students[i].name;
        cout << "Enter the #" << i+1 << " students grade";
        cin >> Students[i].grade;
    }

    sort(Students,numStudents);

    for( int i = 0; i < numStudents; i++) {
        cout << Students[i].name << " got a grade of " << Students[i].grade << endl;
    }

    return 0;
}


void sort(students *Student, int numStudents)
{
    int smallindex;
    students tmp;

    for (int i = 0; i < numStudents; i++) {
        smallindex = i;
        for (int c = i + 1; c < numStudents; c++) {
            if(Student[c].grade > Student[i].grade) {
                tmp = Student[i];
                Student[i] = Student[c];
                Student[c] = tmp;
            }
        }
    }
    
}

