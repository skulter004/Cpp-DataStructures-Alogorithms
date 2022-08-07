#include <iostream>
using namespace std;

//leet code 509 return the desired numbered element from the fibonacci series with 0 indexing
int fibindex(int pos){
    if(pos == 0)
        return 0; 
    if(pos == 1)
        return 1;

    return fibindex(pos-2) + fibindex(pos-1);
}

int main(){

    cout << fibindex(4) << endl;
}