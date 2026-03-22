#include<iostream>

using namespace std;

class Person{
    string name;
    int age;

    public:
        virtual void work() = 0;

};

class Student : public Person{
    
    private:
        int marks;

    public:
        void study(){
            cout<< " Student usually study "<<endl;
        }

        void work() override{
           cout<<"I study.. "<<endl;
        }
};

class Teacher : public Person{

    double salary;

    public:
        void teach(){
            cout<<" Teacher teaches..."<<endl;
        }

        void work() override{
            cout<<"I teach...."<<endl;
        }

};

int main(){

    Student s;
    Teacher t;
    s.work(); // this will create new function work not overrides it
    t.work(); // same as above

            // use override 

    return 0;

}