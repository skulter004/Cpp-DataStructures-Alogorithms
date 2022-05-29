#include<iostream>
using namespace std;

int main(){
    int i=5;
    int *p1= &i;
    int **p2 = &p1;
    cout<<"value of i"<<i<<endl;
    cout<<"value of *p1"<<*p1<<endl;
    cout<<"value of **p2"<<**p2<<endl;
    
    return 0;
}