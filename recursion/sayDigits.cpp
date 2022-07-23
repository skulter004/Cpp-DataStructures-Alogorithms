#include <iostream>
using namespace std;

//say digits 
void saydigits(int n , string *arr0){
        if(n==0)
        return ;

        saydigits(n/10 , arr0);
        cout<<arr0[n%10]<<" ";
}

int main(){
    string arr0[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    saydigits(6969 , arr0);
}