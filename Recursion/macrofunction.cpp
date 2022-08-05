#include <iostream>
using namespace std;
#define max2(a,b) (a>b ? a :b)
void increment( int& c , int& d , int e = 1){
    c++;
    d++;
    cout<<"e= "<<e<<endl;
}

int main(){
     int a=5,b=15;
     cout << max2(a,b) << endl;
     cout << "a= " << a << " b= " << b << endl;
     increment(a,b);
}