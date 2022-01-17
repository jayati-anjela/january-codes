#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

// check if undirected graph is a Tree or not
// if a graph contains a cycle, it is not a tree


class Graph{

    list<int> *l;
    int V;


    public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int x, int y){
        // directed graph
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree( ){
        // graph is array of linked list
        int *parent = new int[V];
        bool *visited = new bool[V];
        queue<int> q;

        //
        for(int i=0; i<V; i++){
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;
        q.push(src);
        visited[src] = true;

        // pop out each node and visit its nbr
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr:l[node]){
                if(visited[nbr] == true and parent[node] != nbr){
                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main(){

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    g.addEdge(0,3);
    if(g.isTree()){
        cout<<"Yes it is a tree.";
    }
    else{
        cout<<"Not a tree.";
    }
    return 0;
}