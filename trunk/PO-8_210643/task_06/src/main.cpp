#include <iostream>
#include <string>
#include <vector>

class Professor;

class Student {
private:
    std::string name = "Alexandra";
    std::string surname = "Serko";
    int age;
    std::vector<class Subject*> subjects; 

public:
    explicit Student(std::string name, std::string surname, int age) : name(name), surname(surname), age(age) {}


    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Name: " << student.name << " Surname: " << student.surname << " Age: " << student.age;
        return os;
    }
    void AddSubject(Subject* subject) {  
        subjects.push_back(subject);
    }
};


class Professor {
private:
    std::string name = "Yana";
    std::string surname = "Sitkovets";
    int age = 0;

public:
    explicit Professor(std::string name, std::string surname, int professorAge) : name(name), surname(surname), age(professorAge) {}

    void ManageEducation() const {
        std::cout << "Professor " << name << " " << surname << " is ruling the education." << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Professor& professor) {
        os << "Name: " << professor.name << " Surname: " << professor.surname << " Age: " << professor.age;
        return os;
    }

};

class Subject {
private:
    std::string name = "OOTP";
    std::vector<Professor> professors; 

public:
    explicit Subject(const std::string& subjectName) : name(subjectName) {}

    void AddProfessor(Professor professor) { 
        professors.push_back(professor);
    }

     friend std::ostream& operator<<(std::ostream& os, const Subject& subject ) {
        os << "Subject: " << subject.name<<" ";
        return os;
    }
    void GetData() const {
        for (const auto professor : professors) {
            std::cout << professor << " ";
        }
    }




};

class Group {
public:
    std::string groupName = "";
    std::vector<Student> students;
    std::vector<Subject> subjects;  
    std::string studyPlan = "";

public:
    explicit Group(const std::string& name) : groupName(name) {}

    void AddStudent(const Student& student) {
        students.push_back(student);
    }

    void AddSubject(Subject subject) {
        subjects.push_back(subject);
    }

    void ManageSchedule() const {
        std::cout << "Managing the education plan  " << groupName << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
        os << "Group: " << group.groupName << " ";
        return os;
    }

    void GetData() const {
        std::cout << "Students \n";
        for (const auto& student : students) {
            std::cout << student << " ";
            std::cout << "\n";
        }
       
        std::cout << "Subjects \n";
        for (const auto& subject : subjects) {
            std::cout << subject << " ";
            subject.GetData();
            std::cout << "\n";
        }
      

    }
};

class University {
public:
    std::string schoolName = "";
    std::vector<Professor*> professors; 
    std::vector<Group> groups;  

public:
    explicit University(const std::string& name) : schoolName(name) {}

    void AddProfessor(Professor* professor) {  
        professors.push_back(professor);
    }

    void AddGroup(const Group& group) {
        groups.push_back(group);
    }

    void ManageClasses() const {

        std::cout << "Managing classes in " << schoolName << std::endl;
        for (const auto group : groups) {
            std::cout << group << std::endl;
        }
    }

  
    

};

int main() {
    University university("BSTU");
    Professor professor1("Samoluk", "Oleg", 27);
    Professor professor2("Yana", "Sitkovets", 24);

    Student student1("Alexandra", "Serko", 19);
    Student student2("Kate", "Makarevich", 19);

    Subject subject1("SP");
    Subject subject2("OOTP");

    Group group("Group PO8");

    university.AddGroup(group);
    subject1.AddProfessor(professor1);  
    subject2.AddProfessor(professor2);
    group.AddSubject(subject1);
    group.AddSubject(subject2);
    group.AddStudent(student1);
    group.AddStudent(student2);
  
    university.ManageClasses();
    group.GetData();


    return 0;
}
