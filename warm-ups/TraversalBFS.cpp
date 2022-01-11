// graph traversal BFS or DFS (breadth first search)-> iterative
// (depth first search) -> recursive

#include<iostream>
#include<queue>
#include<list>
#include<map>

using namespace std;

template<typename T>
class Graph{

    map<T,list<T> > l;

    public:

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        map<T,int> visited;
        queue<T> q;

        q.push(src); // pushing src in queue
        visited[src] = true;

        while(!q.empty()){
            T node = q.front(); 
            q.pop(); // popping so that node becomes 0

            cout<<node<<" ";
            for(int nbr:l[node]){ // for every nbr in list of node
                if(!visited[nbr]){
                    q.push(nbr); // nbr is pushed into the queue if not been visited yet
                    // then marked as visited
                    visited[nbr] = true;
                }
            }
        }
    }



};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

}