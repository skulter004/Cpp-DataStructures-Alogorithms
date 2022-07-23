#include <iostream>
using namespace std;

//print counting
void counting(int limit){
    if(limit == 0 )
        return ;
    
    cout << limit <<" ";
    
    counting(limit-1);
    return ;
}

int main(){
    counting(5);
}