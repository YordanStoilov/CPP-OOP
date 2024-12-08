#include <iostream>
#include <string>
#include <vector>
using std::string;

class Student{
public:
    Student(string name, string surname, double average)
        : name(name), surname(surname), average(average) {}

    double getAverage() { return average; }
    string getName() { return name; }
    string getSurname() { return surname; }

private:
    string name;
    string surname;
    double average;
};

class StudentManager{
public:
    StudentManager(std::istream& stream){
        int numberOfStudents;
        stream >> numberOfStudents;

        for (int i = 0; i < numberOfStudents; ++i){
            string name, surname;
            double grade;

            stream >> name >> surname >> grade;
            Student newStudent(name, surname, grade);
            addStudent(newStudent);
        }
    }
    double getAverageGrade(){
        double totalSum;
        for (Student& student : students){
            totalSum += student.getAverage();
        }
        return totalSum / static_cast<double>(students.size());
    }
    void printStudentsData(std::ostream& stream){
        if (students.empty()){
            stream << "Invalid input" << '\n';
            return;
        }
        for (Student& student : students){
            stream << student.getName() << ' '
            << student.getSurname() << ' '
            << student.getAverage() << '\n';
        }
        stream << getAverageGrade() << '\n';
    }
    void addStudent(Student& student){
        students.push_back(student);
    }

private:
    std::vector<Student> students;
};

int main(){
    StudentManager sm(std::cin);
    sm.printStudentsData(std::cout);
}