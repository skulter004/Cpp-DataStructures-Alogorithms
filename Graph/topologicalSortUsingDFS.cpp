#include<bits/stdc++.h>
using namespace std;

void topSortUTIL(int node, unordered_map<int, bool> &visited, stack<int> &st, 
                unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topSortUTIL(neighbour, visited, st, adj);
        }
    }

    //imp
    st.push(node);
}

//topological sort used only on directed acyclic graph because on cyclic the conditions can not be fullfilled \
it is a linear ordering of vertices such that for every edge u->v u always appear\
before v in that ordering
//logic :: carry out the dfs of graph and push the elements while returning from \
the end into a STACK w'll get the topological sort\
TC = O[n+e] SC = o[n]
vector<int> topologicalSort(vector<vector<int> > edges, int V, int E){
    //create adj list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfstopologicalutil for all components
    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!visited[i]) topSortUTIL(i, visited, st, adj);
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    int n = 7;
    int v = 7; //no of vertex
    vector<vector<int>> edges = {{1, 3}, {1, 2}, {3, 4}, {2, 4}, {4, 5}, {4, 6}, {5, 6}};
    vector<int> topoSort = topologicalSort(edges, v, n);

    for(int i = 0; i < topoSort.size(); i++){
        cout << topoSort[i] << " ";
    }cout << endl;

    return 0;
}