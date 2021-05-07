/*Connor Cheney W0276004*/
#include <string>
#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H


using namespace std;

class Student {
private:
    string name;
    int numCourses;
    string *courses;

public:
    Student();
    virtual ~Student();
    Student &operator=(const Student &rightStu);
    void ResetCourseArray();
    void numCourseReset();
    void gatherUserInput();
    void displayStudentInfo();
    string &getName();
    void setName(const string &name);
    int getNumCourses();
    Student(const Student& stuToCopy);
    void setNumCourses(int numCourses);
    string * getCourses();
    void setCourses(string coursesArray[]);

};


#endif //ASSIGNMENT2_STUDENT_H
