#include<bits/stdc++.h>
using namespace std;



int tour(int petrol[], int distance[], int n){
    
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int  i = 0; i < n; i++){
        balance += petrol[i] - distance[i];
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0){
        return start;
    }
    else{
        return -1;
    }

}

int main(){
    int n = 4;
    int petrol[] = {4,6,7,4};
    int distance[] = {6,5,3,5};
    cout << tour(petrol, distance, n) << endl;
}