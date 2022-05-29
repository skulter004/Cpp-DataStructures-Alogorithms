#include<iostream>
using namespace std;
void update(int &j){
    j++;
}
int main(){
    int i= 0 ;
    int &j = i;
    cout<<j<<endl;
    
    return 0;
}

