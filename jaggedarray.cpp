#include<iostream>
using namespace std;

int main(){
	cout<<"Enter no. of rows: ";
	int n;
	cin>>n;
	
	int **arr = new int*[n];
	int colsN[n]; 
	
	for(int i=0; i<n; i++){
		cout<<"Enter the size of "<<i<<" row: ";
		int temp;
		cin>>temp;
		colsN[i] = temp;
		arr[i] = new int[temp];
	}
	
	//teking input
	
	for(int i=0; i<n; i++){
		for(int j=0; j<colsN[i]; j++){
			cout<<"Enter the value of "<< i<<" "<< j<<endl;
			cin>>arr[i][j];
		}
	}
	
	//printing
	
	for(int i=0; i<n; i++){
		for(int j=0; j<colsN[i]; j++){


			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//releasing memory
	
	for(int i=0; i<n; i++){
		delete []arr[i];
	}
	
	delete []arr;
	
	return 0;
}