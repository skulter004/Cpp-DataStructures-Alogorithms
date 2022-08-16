#include<bits/stdc++.h>
using namespace std;

//in this algo one node is selkected and then all ajacent nodes are visited one by one
//breadth first search used to traverse a graph

//change the list to set if it requires answers in a sorted order
//TC and SCv  O[n+e]
void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        //undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited,
          vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        //store front node into ans
        ans.push_back(front);

        //traverse all neighbours of front node
        for(auto i : adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges){

    //1st have to create adjacenecy listprepareAdjList
    unordered_map<int, list<int> > adjList;
    vector<int> ans;

    //visited map to ensure no nodes is traverse multiple times
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of graph
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}



int main(){
    int n; cout << "Enter the number of Edges " << endl;
    cin >> n;
    int vertex; cout << "Enter the number of vertex" << endl;
    cin >> vertex;
    vector<pair <int, int> > edges;

    cout << "Enter the Edges" << endl;
    for(int i = 0; i < n; i++){
        pair<int, int> temp;
        cin >> temp.first;
        cin >> temp.second;

        edges.push_back(temp);
    }
    vector<int> ans = BFS(vertex, edges);
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
}