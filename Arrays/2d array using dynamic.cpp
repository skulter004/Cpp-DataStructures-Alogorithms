#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int**arr= new int*[n];
    int *size = new int[n];
    // for jagged array
    for(int i=0;i<n;i++){
         cin>>size[i];
         arr[i]= new int [size[i]];
    }

     //for making 2d array
    // for(int i=0;i<m;i++){
    //     arr[i] = new int[n];
    // }

    //taking input from user

    for(int i=0 ;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //printing the elements

     for(int i=0 ;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memeory
    
    for(int i=0;i<n;i++){
        delete[]arr[i];
    }
    delete []arr;

}
	