#include <iostream>
using namespace std;

//reversing a string using recursion
void revString( string &str , int strtIndx , int endIndx ){
    
    if (endIndx < strtIndx ){
        cout << "reverse of the string is " << str << endl;
        return ;
    }

    else{
        swap(str[strtIndx] , str[endIndx]);
    }

    revString(str , strtIndx +1 , endIndx -1 );   
}

int main(){
    
    string str = "sss";
    
    string origstring = str ;

    revString(str , 0 , str.size() -1 );
}