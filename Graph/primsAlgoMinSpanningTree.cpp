#include<bits/stdc++.h>
using namespace std;


//need to create 3 data structures 'KEY(weight) MST PARENT' inittialize mst wiht 0 and parent with -1\
TC is O[n^2]
//optimisation use min heap to get the min value in O[1] the overall TC O[nlogn]
vector<pair<pair<int, int>, int>> PrimsAlgo(int n, int m, vector<pair<pair<int, int>, int>> g){
   
   //adjList
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    //3 structures
    vector<int> key(n+1); // n+1 because suppose 1 is 1st node then we re pointing it with index 1 only
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    //initialize
    for(int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // algo 
    key[1] = 0; // as the source nodes or the nodes are starting from 1
    parent[1] = -1;

    for(int i = 1; i < n; i++){
        int mini = INT_MAX;
        int u;
        //find u ie : the node with min key
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        //mark min node as true
        mst[u] = true;

        //check its adjacent nodes
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i = 2;/*as the parent of 1 is -1*/ i <=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main(){
    int n = 5;
    int m = 14;
    vector<pair<pair<int, int>, int>> edges = {{{1, 2}, 2},
{{1, 4}, 6},
{{2, 1}, 2},
{{2, 3}, 3},
{{2, 4}, 8},
{{2, 5},5},
{{3, 2}, 3},
{{3, 5},7},
{{4, 1},6},
{{4, 2},8},
{{4, 5},9},
{{5, 2},5},
{{5, 3},7},
{{5 ,4},  9}};
    
cout << "HELLO" << endl;
    vector<pair<pair<int, int>, int>> tree = PrimsAlgo(n, m, edges);

    for(int i = 0; i < tree.size(); i++){

        cout << tree[i].first.first << "->" << tree[i].first.second << " w = " << tree[i].second << endl;
    }

}