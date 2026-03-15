#include<iostream>

using namespace std;

class BankAccount{

	private:
		int accountNumber;
		string acountHolderName;
		double balance;

	public:
	    BankAccount(void) : accountNumber(1) , acountHolderName("Rahil") , balance(100000)
		{	
		}

        void deposit(double money){
            this->balance += money;
        }

        void withdraw(double money){
            this->balance -= money;
        }
		
        void display(){
            cout<<"Current balace is : "<<balance<<endl;
        }
};


int main()
{
    BankAccount b1;
    b1.deposit(50000); 
    b1.withdraw(25000); 
    b1.display();

    return 0;

}
	

