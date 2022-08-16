//return the answer in lexicographgical order i e : DLRU
#include<bits/stdc++.h>
using namespace std;

//TC  = (4^n*n) SC = (n*m)                       

bool isSafe(int x, int y, vector<vector<bool>> visited,
            vector<vector<int>> arr, int n)
{
    if((x >= 0 && x < n ) && (y >=0 && y < n) && visited[x][y] != 1 && arr[x][y] == 1){
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> arr, int n, vector<string> &ans, 
            vector<vector<bool>> &visited, string path){

    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }
    //4 movement DLRU
    visited[x][y] = true;
    //down
    if(isSafe(x+1, y, visited, arr, n)){
        solve(x+1, y, arr, n, ans, visited, path + 'D');
    }

    //left
    if(isSafe(x, y-1, visited, arr, n)){
        solve(x, y-1, arr, n, ans, visited, path + 'L');
    }

    //right
    if(isSafe(x, y+1, visited, arr, n)){
        solve(x, y+1, arr, n, ans, visited, path + 'R');
    }

    //up
    if(isSafe(x-1, y, visited, arr, n)){   
        solve(x-1, y, arr, n, ans, visited, path + 'U');
    }
    //remove the visited mark when coming back
    visited[x][y] = 0;
}

//return the direction as the answer
vector<string> ratMaze(vector<vector<int> > maze, int n){
    vector<string> ans;
    vector<vector<bool>> visited (n, vector<bool>(n,0));
    string path = "";

    solve(0, 0, maze, n, ans, visited, path);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = ratMaze(maze, n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

}