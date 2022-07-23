#include<iostream>
#include<stack>
using namespace std;
//to find the min cost to make a string valid like {{}}}} is not valid but we \
can make it by changing the brackets formation \ 2 things we have to take \
no of open count and no of close count  and the expression will be (a +1)/2 + (b+1)/2\

int findMinCost(string str){

    if(str.length() % 2 != 0){
        return -1;
    }
    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(ch == '{')
        
        s.push(ch);
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else
            s.push(ch);
        }
    }

    int closeCount = 0 , openCount= 0;
    while(!s.empty()){
        if(s.top() == '{'){
            openCount++;
        }
        else{
            closeCount++;
        }
        s.pop();
    }

    int ans = (closeCount + 1)/2 + (openCount + 1)/2;
    return ans;
}
int main(){
    string str ="{}";

    cout << findMinCost(str) << endl;
}