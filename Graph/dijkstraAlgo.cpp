#include<bits/stdc++.h>
using namespace std;


//TC O[e logv] edges and vertex SC = O[n + e]
vector<int> Dijkstra(vector< vector<int>> edge, 
                    int vertices, int edges, int source)
{
    //adj list
    unordered_map<int, list<pair<int,int>>> adj;
    
    for(int i = 0; i < edges; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);

    //creation of distance array
    for(int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
    }

        //set creation on basis (distance, node)
        set<pair<int,int>> st;

        //innititalize set and dist from source node
        dist[source] = 0;
        st.insert(make_pair(0, source));

        while(!st.empty()){
            //fetch top record
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            //remove record from top
            st.erase(st.begin());

            //traverse on neighbours
            for(auto neighbour: adj[topNode]){
                if(nodeDistance + neighbour.second < dist[neighbour.first]){
                    //checking if a record is already present in the set for the\
                    same node if present then have to remove it
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    
                    //record found
                    if(record != st.end()){
                        st.erase(record);
                    }

                    //distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    
                    //record push in set
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }

    return dist;
}
int main(){
    int vertices = 4, edges = 5, source = 0;
    vector< vector<int>> edge = {{0, 1, 5}, {0, 2, 8}, 
                                {1, 2, 9}, {1, 3, 2}, {2, 3, 6}};

    vector<int> dist = Dijkstra(edge, vertices, edges, source);

    for(int i = 0; i < dist.size(); i++){
        cout << dist[i] << " ";
    }cout << endl;

    return 0;
}