#include<bits/stdc++.h>
using namespace std;

//adjacency list method w'll have to create a map also to keep the track of the list to the nodes
//to make the graph generic in nature now we can create a graph of any data type after specifying in the object creation
template <typename T>
class graph{

public:
    unordered_map<T,list<T>> adj;

    void addEdge(T E1, T E2, bool direction){
        //direction is to check whether w're creating a directed or undirected graph
        //direction -> 0 undirected 
        //direction -> 1 directed
        //create and edge from e1 to e2
        adj[E1].push_back(E2);

        if(direction == 0){
            adj[E2].push_back(E1);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j :i.second){
                cout << j << ", ";
            }cout << endl; 
        }
    }

};

int main(){
    int n; cout << "Enter the number of Nodes" << endl;
    cin >> n;

    int m; cout << "Enter the number of Edges" << endl;
    cin >> m;

    graph<int> g;
    for(int i = 0; i < m; i++){
        int E1, E2;
        cin >> E1 >> E2;
        //creating undirected graph
        g.addEdge(E1, E2, 0);
    }
    //priting
    g.printAdjList();
}