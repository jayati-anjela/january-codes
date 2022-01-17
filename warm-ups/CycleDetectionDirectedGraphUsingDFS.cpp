#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

// check if directed graph contains a cycle or not


class Graph{

    list<int> *l;
    int V;


    public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int x, int y, bool directed = true){
        // directed graph
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }

    bool cycleHelper(int node, bool *visited, bool *stack){

        // visit a node
        visited[node] = true;
        stack[node] = true;

        for(int nbr: l[node]){

            //two cases
            if(stack[nbr]==true){ // case of back edge
                return true;
            }

            if(visited[nbr]== false){
                bool cycleMilGaya = cycleHelper(nbr, visited, stack);
                if(cycleMilGaya == true){
                    return true;
                }
            }

        }
        // leave a node
        stack[node] = false;
        return false;
    }
    

    bool containsCycle(){

        // Check for cycle in Directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];

        for(int i=0; i<V; i++){
            visited[i] = stack[i] = false;
        }

        return cycleHelper(0, visited, stack);


    }
};

int main(){

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);

    g.addEdge(4,2); // Back Edge
    if(g.containsCycle()){
        cout<<"Yes it contains a cycle.";
    }
    else{
        cout<<"No, it does not contain a cycle.";
    }
    return 0;
}