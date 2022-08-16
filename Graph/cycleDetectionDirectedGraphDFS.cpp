#include<bits/stdc++.h>
using namespace std;

// TC O[n + e] nodes + edges SC  is linear O[n]

bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
    unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int> > &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if(cycleDetected) return true;
        }
        else if(dfsVisited[neighbour]) return true;
    }

    dfsVisited[node] = false;
    return false;
}

//cycle detection
string detectCycle(int n, vector<vector<int> > edges){
    //adl list creation
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < n; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs for all component
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 0; i <= n; i++){
        bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
        if(cycleFound) return "YES";
    }
    return "NO";
}

int main(){
    int n = 4;
    vector<vector<int> > edges = {{1, 2}, {2, 3},{3, 4}, {4,5} };
    cout << detectCycle(2, edges) << endl;
}