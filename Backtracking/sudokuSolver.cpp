#include<bits/stdc++.h>
using namespace std;

//sudoku conditions no duplicate numbers in any row or any column each digit from 1 to 9\
should ony occur once in the individual matrix of 3*3 in the matrix
//formula for checking 3*3 matrix ==> sudoku[3*(row/3) + i/3][3*(col/3) + 1%3]
//TC = O[9^m] m = no of empty spaces SC  ==> O[1]
bool isSafe(int row, int col, vector<vector<int>> sudoku, int val){
    
    for(int i = 0; i < sudoku.size(); i++){
        //row check
        if(sudoku[row][i] == val) return false;
        //col check
        if(sudoku[i][col] == val) return false;
        //3*3 matrix check
        if(sudoku[3*(row/3) + i/3][3*(col/3) + 1%3] == val) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku){
    int n = sudoku[0].size();

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            //cell empty
            if(sudoku[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row, col, sudoku, val)){
                        sudoku[row][col] = val;
                        
                        //recursive call
                        bool nextSolutionPossible = solve(sudoku);
                        if(nextSolutionPossible) return true;

                        else{
                            //backtrack
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> sudoku){
    solve(sudoku);
}

int main(){
    vector<vector<int>> sudoku(9,vector<int>(9,0)) ; /* = {{3,0,6,5,7,8,0,9,2},{5,2,9,1,3,4,7,6,8},{4,8,0,6,2,9,5,3,1},
                                 {2,6,3,4,1,5,9,8,7},{9,7,4,8,6,3,1,2,5},{8,5,1,7,9,2,6,4,3},
                                 {1,3,8,9,4,7,2,5,6},{6,9,2,3,5,0,8,7,4},{7,4,5,2,8,6,3,1,9}} ;*/
    solve(sudoku);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << " ";
        }cout << endl;
    }
}