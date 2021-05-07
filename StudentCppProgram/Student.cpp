/*Connor Cheney W0276004*/
using namespace std;
#include "Student.h"
#include <iostream>
#include <regex>






void Student::ResetCourseArray()
{
    if (courses) {
        delete[] courses;
        courses = nullptr;
        numCourses = 0;
    }
}

/*loop for user input*/
void Student::gatherUserInput(){
    string studentName;
    string className;
    int indexCounter = 0;
    /*starting size of array*/
    int arraySize = 1;

    auto *coursesArr = new string[arraySize];

    /*Regex source: https://www.regextester.com/93648 */
    regex nameRegex("^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$");

    cout << "Student Course Tracker.\n"
            "Please enter the students name:";
    cin >> studentName;

    do{
        if(!regex_match(studentName,nameRegex)) {
            cout << "Please enter a valid name, try again:";
            cin >> studentName;
        }
        /*keeps trying to get right name, until the name matches regex*/
    }while(!regex_match(studentName,nameRegex));

    cout << "Please enter the courses " + studentName + " is taking." << endl;
    cout << "Enter the courses one at a time, typing !quit to finish." << endl;
    do{
        cout << "Enter course name (!quit to finish):" << endl;
        cin >> className;
        /*after getting course name, check if its empty or !quit*/
        if(className != "!quit" && !className.empty()){
            /*if the array is full, fill new temp with info*/
            if (indexCounter == arraySize) {
                arraySize = arraySize * 2;
                auto *tempCourseArr = new string[arraySize];
                for (int i = 0; i < indexCounter; ++i) {
                    tempCourseArr[i] = coursesArr[i];
                }
                /*main array updated*/
                coursesArr = tempCourseArr;
            }
        //adding course to array
        coursesArr[indexCounter] = className;
        /*IndexCounter is keeping track of how many times the user*/
        /*has entered a valid class, it keeps track of course number and*/
        /*index slot for each new course*/
        indexCounter++;
        }
        /*loop ends on !quit*/
    }while(className != "!quit");
    /*saturating class property*/
    courses = new string[arraySize];
    for(int i = 0; i < indexCounter; i++){
        courses[i] = coursesArr[i];
    }
    /*Setting total courses and student name*/
    Student::setNumCourses(indexCounter);
    Student::setName(studentName);
}

Student::Student() = default;

Student::~Student() {
    cout << "DESTRUCTOR" << endl;
    name = "";
    numCourses = 0;
    Student::ResetCourseArray();
}
Student::Student(const Student& stuToCopy) {
    cout << "COPY CONSTRUCTOR" << endl;

    numCourses = stuToCopy.numCourses;
    courses = new string[stuToCopy.numCourses];
    for(int i = 0; i < numCourses; i++) {
        courses[i] = stuToCopy.courses[i];
    }
}

Student& Student::operator = (const Student &rightStu) {
    cout << "ASSIGNMENT OPERATOR" << endl;

    if (this != &rightStu) {
        name = rightStu.name;
        numCourses = rightStu.numCourses;
        courses = new string[rightStu.numCourses];
        copy(rightStu.courses, rightStu.courses + numCourses, courses);
        return *this;
    } else{
        return *this;
    }

}
/*displays all the main student data*/
void Student::displayStudentInfo() {
    cout << "Student Name: " << name << endl;
    cout << "Number of Courses: " << numCourses << endl;
    cout << "Courses: ";
    /*loop to print out arrays data*/
    for (int i = 0; i < numCourses; i++) {
        /*if its the last element in the array use a period*/
        if(i==numCourses-1){
            cout << courses[i] << "." << endl;
        }else{
            cout << courses[i] << ", ";
        }

    }

}

string &Student::getName() {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getNumCourses() {
    return numCourses;
}

void Student::setNumCourses(int numCourses) {
    Student::numCourses = numCourses;
}


