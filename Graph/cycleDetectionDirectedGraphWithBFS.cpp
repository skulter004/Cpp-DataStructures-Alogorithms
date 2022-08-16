#include<bits/stdc++.h>
using namespace std;

//logic :: if the given gragh is a DAG the w'll be able to get its valid topSort\
but it it is cycle graph then w'll not be able to get valid topSort some what same to \
the KAHN'S algo if we get a invalid topSort that means a cycle is present VERY EASY:| \
TC = O[n+e] SC = o[n]
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> edges){
    //create adj list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first -1; //if the nodes start from 1 then use -1 if fromt 0 remove it
        int v = edges[i].second -1; // or star the below indegree loop from 1 to n-1

        adj[u].push_back(v);
    }

    //find all indegree
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //push 0 indegree into the queue
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //do BFS
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //inc count
        count++;

        //neighbour indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(count == n)//means a valid topological sort if the no of count is equal to n
        return false;

    else return true;
}

int main(){
    int n = 5;
    vector<pair<int, int> > edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    if(detectCycleInDirectedGraph(n, edges)) 
        cout << "Cycle is present ";
    
    else cout << "Cycle not present"; 

    cout << endl;
    return 0;
}