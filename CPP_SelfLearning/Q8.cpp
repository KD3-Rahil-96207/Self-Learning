#include<iostream>
using namespace std;

class Programmer{

    public:

    Programmer(){
        cout<<" Programmer() ctor"<<endl;
    }

        void work(){
            cout<<"I write programms........"<<endl;
        }
   

};

class Teacher{

    public:

        Teacher(){
        cout<<" Teacher() ctor"<<endl;
    }


        void work(){
            cout<<"I teach Students........"<<endl;
        }

};

class ProgrammingTeacher : public Programmer , public Teacher {

    public:
            
            ProgrammingTeacher(){
                cout<<" ProgrammingTeacher() ctor "<<endl;
            }


};

int main(){

    ProgrammingTeacher pt;
    pt.Teacher::work();
    pt.Programmer::work();

    // ctor calling

}