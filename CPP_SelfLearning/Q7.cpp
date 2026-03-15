#include<iostream>

namespace college{
    class Student{
        int rollno;
        std::string name;

        public:
        Student() : rollno(1) , name("Rahil")
        {
        }
        Student(int rollno, std::string name) : rollno(rollno) , name(name)
        {
        }

        void setRecord(int rollno, std::string name){
            this->rollno = rollno;
            this->name = name;
        }

        void getRecord(void){
            std::cout<<"Rollno : "<<this->rollno<<std::endl;
            std::cout<<"Name : "<<this->name<<std::endl;
        }

    };
    
    class Teacher{
        int TeacherID;
        std::string name;
        std::string Subject;


        public:
        Teacher() : TeacherID(1) , name("Parul") ,Subject("English")
        {
        }
        Teacher(int TeacherID , std::string name) : TeacherID(TeacherID) , name(name) , Subject(Subject)
        {
        }

        void setRecord(int TeacherID, std::string name){
            this->TeacherID = TeacherID;
            this->name = name;
        }

        void getRecord(void){
            std::cout<<"TeacherID : "<<this->TeacherID<<std::endl;
            std::cout<<"Name : "<<this->name<<std::endl;
        }
        
        // In this case getter an Dispaly function will do the same thing so writing only getter

   };
}

int main(){
    using namespace college;

    Student s1;
    Teacher t1;
    s1.getRecord();
    t1.getRecord();
}