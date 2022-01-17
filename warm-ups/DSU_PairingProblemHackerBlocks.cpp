#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    list<pair<int,int> > l;

    public:

    Graph(int V){
        this->V = V;
    }

    void addEdge(int u, int v){
        l.push_back(make_pair(u,v));
    }

    //Find
    int findSet(int i, int parent[]){
        //base case
        if(parent[i]==-1){
            return i;
        }


        // updating parent val to optimise the path between parent and curr node
        return parent[i] = findSet(parent[i],parent); 
   }



    // Union
    void unionSet(int x, int y, int parent[], int rank[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if(s1!= s2){

            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool containsCycle(){

        // DSU logic to check if graph contains cycle or not
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i=0; i<V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        //Iterate over the edgelist
        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1!=s2){
                unionSet(s1, s2, parent, rank);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        return false;
    }

    int pairing(){

        //Init DSU Logic

        int *parent = new int[V];
        int *rank = new int[V];

        for(int i=0; i<V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        //Code logic

        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            unionSet(s1, s2, parent, rank);
        }

        // go to all the nodes
        int ans = 0;
        for(int i=0; i<V; i++){
            ans += V - rank[findSet(i,parent)];  // rank[super parent of i]

        }
        delete [] parent;
        delete [] rank;
        return ans/2;
    }


};

int main() {

    int n, m;
    cin>>n>>m;
    Graph g(n);

    while(m--){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }

    cout<<g.pairing()<<endl;

    return 0;
}
