#include<iostream>
#include<stack>
//redundant ->  ((A+B))
using namespace std;

bool redundantCheck(string &str){
    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
            s.push(ch);
        }
        else{
            if(ch ==')'){
                bool isredundant = true;
                while(s.top() != '('){
                    char t = s.top();
                    if(t == '(' || t == '+' || t == '-' || t == '*' || t == '%' ){
                        isredundant = false;
                    }
                    s.pop();
                }
                if(isredundant){
                    return true;
                    s.pop();
                }
                
        }
    }
    }

    return false;
}

int main(){
    string s = "(a+b)";
    cout << redundantCheck(s);
}