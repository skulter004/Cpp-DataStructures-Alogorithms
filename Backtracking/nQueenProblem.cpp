#include<bits/stdc++.h>
using namespace std;
// TC is [n!] SC is O[n*n]
//n queens is a puzzle is the problem N chess queen on a N*N chessboard such that no\
two queens attack each other
//conditions not two queens should be in same row, column or diagonal to each other

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){

    vector<int> temp;

    for(int i = 0; i < n; i++){
        for(int  j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

//optimisation we are checking safe funtion in O[n] so for this we can create a map for the \
case of rows for diagonals the value of each lower left diagonal is same if we do sum of its row and col index \
and in case of upper left diagonal there is a formula as (n-1) + col-row do it on your own 
bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;

    //check for same row
    while(y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }//no need to check column as we are inserting from left to right and placing onlyy 1 queen in a columns
   
    x = row;
    y = col;
    //check for left diagonals
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }

    //check for bottom left diagonals;
    x = row;
    y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1) return false;
        x++;
        y--;
    }

    return true;

}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    //base case all columms filled
    if(col == n){
        addSolution(ans, board, n);
        return;
    }
    //solve 1 case and use recursion
    for(int row = 0; row < n; row++){

        if(isSafe(row, col, board, n)){

        //if placing queen is safe
        board[row][col] = 1;
        solve(col+1, ans, board, n);

        //backtrack
        board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n){
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0/* satart col */, ans, board, n);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> ans = nQueen(n);
    cout << "Answer is " << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }    
    }cout << endl;
}