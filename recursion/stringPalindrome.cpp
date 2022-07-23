#include <iostream>
using namespace std;

//string palindrome using reccursion mostly same as of reversing string
bool checkPal( string str , int strtIndx , int endIndx ){
    
    if (endIndx < strtIndx){
        return 1 ;
    }

    if(str[strtIndx] != str[endIndx]){
        return 0;
    }
    else{
        return checkPal ( str  , strtIndx +1 , endIndx -1);
    }      
}

int main(){

    string str = "sss";
    
    string origstring = str ;
    
    if(checkPal(str , 0 , str.size() -1 )){
        cout << "string is a valid palindrome " <<endl;
    } 
    else{
        cout << "string is not a valid palindrome " << endl;
     }
}