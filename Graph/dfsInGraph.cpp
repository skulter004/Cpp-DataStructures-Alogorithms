#include<bits/stdc++.h>
using namespace  std;

void dfs(int node, unordered_map<int,bool> &visited,
            unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    //for every connected node recursive call
    for(auto i: adj[node]){
        if(!visited[i]){
        dfs(i, visited, adj, component);
        }
    }
}

//dfs traversal
vector<vector<int> > depthFS(int V, int E, vector<vector<int> > edges){
    
    //adj list making
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    //for all nodes call dfs if not visited
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;

}

int main(){
    int V = 5;
    int E = 4;
    vector<vector<int> > edges = { {0,2}, {0,1}, {1,2}, {3,4}};
    vector<vector<int>> ans = depthFS(V, E, edges);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
}