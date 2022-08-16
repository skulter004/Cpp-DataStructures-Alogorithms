#include<bits/stdc++.h>
using namespace std;

//TC = O[n] linear time same as bfs

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleDtetected = isCyclicDFS(neighbour, node, visited, adj);
                if(cycleDtetected) return true;
            }

            else if(neighbour != parent && /*this can be removed*/ visited[neighbour]){
                //cycle present
                return true;
            }
        
    }
    return false;
}

//in undirected graph
//cycle can be detected using both bfs and dfs
string cycleDetection(vector<vector<int> > edges, int n){

    //create adjacency list 
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < n; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //2handle disconnected component
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans) return "YES";
        }
    }
    return "NO";
}

int main(){
    int n = 3;
    vector<vector<int> > edges = {{1, 2}, {2, 3}, {1, 3}};
    cout << cycleDetection(edges, n) << endl;
}