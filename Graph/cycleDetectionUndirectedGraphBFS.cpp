#include<bits/stdc++.h>
using namespace std;

//TC = O[n]
bool isCyclicBFS(int src, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    //to keep track of the parent of the nodes
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front]){
            if(visited[neighbour] == 1 && neighbour != parent[front]) 
                return true;

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
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
            bool ans = isCyclicBFS(i, visited, adj);
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