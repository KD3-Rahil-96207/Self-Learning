#include<iostream>

using namespace std;

class Students{

	private:
		int rollno;
		int marks;
		static int highestMarks;

	public:
		void printRecord(void)
		{
			cout<<"Roll no : "<<rollno<<endl;
			cout<<"Marks : "<<marks<<endl;	
		}

		static void sethighestMarks(int marks){
			
			Students::highestMarks = marks;
		} 	
		
		static int printHighestMarks( void){
			return Students::highestMarks;
		}
		
		void setRecord()
		{
			cout<<"Enter rollno : "<<endl;
			cin>>rollno;
			cout<<"Enter Marks : "<<endl;
			cin>>marks;
			if(this->marks > Students::printHighestMarks()){
				Students::sethighestMarks(this->marks);
			}
		}

};
int Students::highestMarks = 0;
int main()
{
	int n;
		bool exitloop = false;
	cout<<"Enter the number of students : "<<endl;
	cin>>n;
	Students *arr = new Students[n];

	while(!exitloop){

	cout<<"1. Add Students 2. Display Students 3. Highest marks 4. EXIT "<<endl;
	
	int choice;
	cout<<"Enter your choice: "<<endl;
	cin>>choice;

	switch (choice)
	{
	case 1: for(int i = 0; i < n; i++)
		{
			arr[i].setRecord();
		}
		break;
	
	case 2: for(int i = 0; i < n; i++)
		{
			arr[i].printRecord();
		}
		break;

	case 3:	cout<<"Highest Marks is : "<<Students::printHighestMarks()<<endl;
		break;
	
	case 4: exitloop = true;
		break;
	}

	}	
	if(arr != NULL){
		delete[] arr;
	}

}
	

