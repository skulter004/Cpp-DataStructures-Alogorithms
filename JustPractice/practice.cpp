#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool isPalindrome(string s) {
        
        string newS ;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 'A' && s[i] <='Z') ||( s[i] >= 'a' && s[i] <= 'z' ) || (s[i] >='0' && s[i] <='9' )) 
                newS[j++] = s[i];
                cout << newS[j] << endl;
        }
        
        string temp = "";
        cout << newS;
        for(int i = 0; i < newS.length();  i++){
            newS[i] = tolower(newS[i]);
        }

        cout << newS;
        
        j = 0;
        for(int i = newS.length()-1; i >= 0; i--){
            temp[j++] = newS[i];
        }



        if(newS == temp) return true;
        
        else
           return false;
    }
int main(){
    vector<int> nums;
    string str = "shivam";
    cout << isPalindrome(str) << endl;

}
