#include<iostream>

using namespace std;

class Laptop{

	private:
		int brandId;
		int price;
		

	public:
		Laptop(): brandId(1) , price(50000)
        {	
            cout<<"Laptop Constructor Called"<<endl;
		}
		
        ~Laptop()
        {
            cout<<"Laptop Destructor Called"<<endl;
        }

        void display(){
            cout<<"BrandID : "<<this->brandId<<endl;
            cout<<"Price of the laptop : "<<this->price<<endl;
        }
};

int main(){

    Laptop l1;
    l1.display();
    

    return 0;
}