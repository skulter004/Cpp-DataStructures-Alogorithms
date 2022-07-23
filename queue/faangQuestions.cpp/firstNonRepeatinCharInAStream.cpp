#include<bits/stdc++.h>
using namespace std;

// string FirstNonRepeating(string input){
//     int arr[26] = {0};
//     queue<int> q;
//     string ans = "";

//     for(int i = 0; i < input.length(); i++){
//         cout << input[i] << endl;
//         arr[ 97 - (int)input[i] ]++;

//         q.push((int)input[i]);

//         while(!q.empty()){
//             if(arr[ 97 - q.front() ] > 1){
//                 q.pop();
//             }
//             else{
//                 ans.push_back((char)q.front());
//                 break;
//             }
//         }
//         if(q.empty()){
//             ans.push_back('#');
//         }
//     }

//     return ans;
// }
    string FirstNonRepeating(string input){
        unordered_map<char,int> count;
        queue<int> q;
        string ans = "";
        for(int i = 0; i < input.length(); i++){
            char ch = input[i];
            count[ch]++;

            q.push(ch);

            while(!q.empty()){
                if(count[q.front()] > 1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }  
        return ans;
    }
int main(){
    string input = "aabc";
    string ans = FirstNonRepeating(input);
    cout << ans << endl;
}