
// WILL COMPLETE LATER 

#include<iostream>

using namespace std;

int strlen(string a){
    int length = 0;
    while(a[length] != '\0'){
        length++;
    }
    return length;
}

int main()
{  
    string st;
    cout<<"Enter a string : "<<endl;
    cin>>st;
    
    cout<<"Length of the String is : "<<strlen(st);
    return 0;

}
