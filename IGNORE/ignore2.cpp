#include<iostream>
#include<vector>
using namespace std;

string numToWord(int num){

    string ans;

    vector<string> ones = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(num/10 == 0) return ones[num%10];

    vector<string> twoDigits = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"};
    if( num < 20 && num/100 == 0) return twoDigits[num %10];

    vector<string> tens = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> hundred;
    vector<string> thousand;
    
    while(num != 0 ){
        int temp = num%10;
        num = num/10;
        ans = ones[temp] + ans;
    }
}

int main(){
    cout << numToWord(1111);
}