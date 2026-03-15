#include<iostream>
using namespace  std;




inline double Powr(double a , double b)
{
	int  result = 1;
	for(int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
	
}

inline double factorial(int x)
{
	int fact = 1;
	if(x < 2) return 1;
	while(x>1)
	{
		fact = fact * x;
		x--;
	}
	return fact;
}

int main()
{
	double a , b;
	cout<<"Enter the base : "<<endl;
	cin>>a;
	cout<<"Enter the power : "<<endl;
        cin>>b;
	cout<<Powr(a,b)<<endl;
	
	double c;
	cout<<"Enter a value: "<<endl;
	cin>>c;
	cout<<"Factorial : "<<factorial(c)<<endl;

	return 0;
}

