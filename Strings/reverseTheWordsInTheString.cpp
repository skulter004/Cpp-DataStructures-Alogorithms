#include<iostream>
#include<vector>

using namespace std;

void revstr( string str){
    int s=0;
    int e=str.length()-1;
    while(s<=e){
        swap(str[s],str[e]);
        s++;
        e--;
    }
    cout<<str<<" ";
    return;
}

int main(){
    string str;
    getline(cin,str);

    revstr(str); 
    return 0;
}