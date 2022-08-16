#include<bits/stdc++.h>
using namespace std;

//find shortst path from source node to destination node\
logic:: create adjList create two structure to keep track visited and parent make a\
queue now start fromt adj list of first push all the element of its adjList into queue\
and mark them visited and enter their theri parent in the structure now keep doing until end\
now take parent structure and get the source and destination node now start from the\
destination nodes get its parent now get the parent of the parent do this until the\
source detination is reached and keep track of this w'll get the ans in reverse order \
so we need to reverse it now to get the actual ans
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t){
    //s & t are source and destination respectively
    //create adj list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first; 
        int v = edges[i].second; 

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    parent[s] = -1;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    //prepare shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    //reversing the answer
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    int n = 7;
    int m = 8;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 7}, {4,6}, {5,7}, {6,7}};
    int src = 1;
    int dst = 7;
    vector<int>ans = shortestPath(edges, n, m, src, dst);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}