#include <iostream>
using namespace std;

//printing fibonacci
void fibnac(int a , int b,int length){
    
    if(length==0)

        return ;

    cout<< a << " " ; 

    fibnac(b,a+b,length-1);

    return ;
}

int main(){
    fibnac(0,1,10);
}