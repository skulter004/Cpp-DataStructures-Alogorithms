#include <iostream>
using namespace std;

// stair problem  //get the no of ways of getting to the nth numbr of stairs
int stair(int nthstair){
     if(nthstair < 0)
       return 0;
     if(nthstair == 0)
       return 1;

       return stair(nthstair-1) +  stair(nthstair-2);
}

int main(){
    cout << stair(4) << endl;
}