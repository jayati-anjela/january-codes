#include<bits/stdc++.h>
using namespace std;

// Cycle Detection in undirected graph using DSU
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
    void unionSet(int x, int y, int parent[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if(s1!=s2){
            parent[s1] = s2;
        }
    }

    bool containsCycle(){

        // DSU logic to check if graph contains cycle or not
        int *parent = new int[V];
        for(int i=0; i<V; i++){
            parent[i] = -1;
        }

        //Iterate over the edgelist
        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1!=s2){
                unionSet(s1, s2, parent);
            }
            else{
                cout<<"Same parents "<<s1<<" and "<< s2<<endl;
                return true;
            }
        }
        delete [] parent;
        return false;
    }


};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.containsCycle()<<endl;

    return 0;
}
