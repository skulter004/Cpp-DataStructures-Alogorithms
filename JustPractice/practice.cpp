#include<iostream>
using namespace std;

int lastLength(string str){
    int len = str.length();
    int ans = 0;
    for(int i = len-1; i >= 0; i--){
        if (str[i] == ' ') break;
        
        ans++;
    }
    return ans;
}

int main(){
    cout << lastLength("shivam singh is a student of jecrc university");
}
