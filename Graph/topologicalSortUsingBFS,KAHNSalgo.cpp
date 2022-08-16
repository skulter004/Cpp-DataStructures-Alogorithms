#include<bits/stdc++.h>
using namespace std;

//logic :: find index of all nodes get their indegree start from the 0 indegree insert it into get the \
queue front insert into ans insert all its connnecting nodes to queue and if their indegree is zero and decrease their indegree by 1 \
repeat this procces until end do BFS \
TC = O[n+e] SC = o[n]
vector<int> topologicalSort(vector<vector<int>> edges, int V, int E){
    //create adj list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegree
    vector<int> indegree(V);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //push 0 indegree into the queue
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //do BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
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