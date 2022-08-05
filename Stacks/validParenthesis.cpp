#include<iostream>
#include<stack>
using namespace std;

bool matches(char top ,char ch){
    if( (ch == ')' && top =='(') || (ch == ']' && top =='[') || (ch == '}' && top =='{') )
        return true;
    else
        return false;
        
}

bool validParenthesis(string input){

    stack<char> s;
    for(int i = 0; i < input.length(); i++){
        char ch = input[i];
        //opening bracket push
        if(ch == '(' || ch == '{' || ch == '[' ){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if(matches(top, ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        
        else{
            return false;
        }
        }

    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string input = "({[[()]]})";
    cout << validParenthesis(input) << endl;
}