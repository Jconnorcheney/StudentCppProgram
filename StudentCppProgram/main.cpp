#include <iostream>
#include <regex>
#include <string>
#include <ostream>
#include <cstdlib>
#include "Student.h"

using namespace std;
/*Connor Cheney W0276004*/
int main() {
    /*Regex source: https://www.regextester.com/93648 */
    regex nameRegex("^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$");
    string studentName;

    /*get student one info*/
    Student studentOne, studentThree;
    studentOne.gatherUserInput();

    /*display student one info*/
    cout << "/*Student One*/" << endl;
    studentOne.displayStudentInfo();


    /*student two as a copy of student one*/
    Student studentTwo(studentOne);
    /*reset everything but name for student one*/
    studentOne.ResetCourseArray();
    cout<<endl;
    /*get student twos name, same validation as gatherUserInput();*/
    cout <<"Please enter student twos name:";
    cin >> studentName;
    do{
        if(!regex_match(studentName,nameRegex)) {
            cout << "Please enter a valid name, try again:";
            cin >> studentName;
        }
    }while(!regex_match(studentName,nameRegex));
    /*set student twos new name*/
    studentTwo.setName(studentName);
    cout << endl;

    /*showing that student one data is cleared*/
    cout << "/*Student one post clear*/" << endl;
    studentOne.displayStudentInfo();
    cout << endl;

    /*display student two data*/
    cout<<endl;
    cout << "/*Student Two*/" << endl;
    studentTwo.displayStudentInfo();

    /*show the copy of student two as student three*/
    studentThree = studentTwo;
    cout<<endl;
    cout << "/*Student Three*/" << endl;
    studentThree.displayStudentInfo();

    return 0;
}
