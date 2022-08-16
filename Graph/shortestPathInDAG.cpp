#include<bits/stdc++.h>
using namespace std;

/*                       0
                     1 /   \ 3
                      /     \
                     \/  2  \/
                     1------>2 
                   6 |   7 / |\
                     |    /  |4\2
                     \/ \/   \/ \
                       3---->4-->5
                         -1   -2  */  //weighted graph  TC = O[n+e] SC = o[n+e]<- including adjlist
                        


//logic::first get the topological sort now we will do some changes in the adjList\
as the graph is weighted it will be like <int, list<pair<int,int> > > \\
EG: it is like 0 -> [1,5],[2,3] 1 and 2 are nodes wile 5 and 3 are weights\
now create a distance array and keep updating it regularly if the next\
distance is lesser than the previous rest w'll see in the code below
class Graph{
public:
    unordered_map<int, list<pair<int, int> > > adj;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v ,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j: i.second){
                cout << "(" <<j.first << "," << j.second << "),"; 
            }cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &distance, stack<int> &topo){
    
        distance[src] = 0;

        //now update the distance of the top element from the adjacency list
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(distance[top] != INT_MAX){
                for(auto i: adj[top]){
                    if(distance[top] + i.second < distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }

};

int main(){
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;

    //topological sort
    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.dfs(i, visited, st);
        }
    }

    int src = 1;
    vector<int> distance(n);
    for(int i = 0; i < n; i++)
        distance[i] = INT_MAX;

    g.getShortestPath(src, distance, st);

    cout << "Ans is " << endl;

    for(int i = 0; i < distance.size(); i++){
        cout <<distance[i] << " ";
    }cout << endl;

}