#include<iostream>
#include<vector>
using namespace std;

class Matrix{
    int size;
    vector<vector<int>>mtx;

    public:
        
        Matrix(int size){
            this->size = size;
            mtx.resize(size, vector<int>(size));
        }

        void acceptMatrix(){
            

            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++){
                    cout << i << " " << j << ": ";
                    cin>>mtx[i][j];
                }
            }
            
        }
        
        void displayMatrix(){
            
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++){
                    cout<<mtx[i][j]<<" ";
                }
                cout<<endl;
            }
            
        }

        Matrix operator+( Matrix &other){
            Matrix temp(size);
                  
            temp.mtx.resize(size, vector<int>(size));
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++){
                    temp.mtx[i][j] = this->mtx[i][j] + other.mtx[i][j];
                }
            }

            return temp;
        }

        Matrix operator-( Matrix &other){
            Matrix temp(size);
                  
            temp.mtx.resize(size, vector<int>(size));
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++){
                    temp.mtx[i][j] = this->mtx[i][j] - other.mtx[i][j];
                }
            }

            return temp;
        }

        Matrix operator*( Matrix &other){
            Matrix temp(size);
                  
            temp.mtx.resize(size, vector<int>(size));
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++){
                    temp.mtx[i][j] = 0;
                    for(int k = 0; k < size; k++){
                        temp.mtx[i][j] += this->mtx[i][k] * other.mtx[k][j]; 
                    }
                }
            }

            return temp;
        }

};

int main(){
    
    Matrix m1(2), m2(2);
    m1.acceptMatrix();
    m2.acceptMatrix();
    

    cout << "result: " << endl;

    Matrix m3(2);
    m3 = m1*m2;
    m3.displayMatrix();
    return 0;
}