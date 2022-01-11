#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{

    map<T, list<T> > l;
    public: 
    void addEdge(T x, T y){
        l[x].push_back(y);
        // l[y].push_back(x);

    }

        
    void dfs_helper(T src, map<T,bool> &visited, list<T> &ordering){
        // Recursive function that will traverse the graph
        visited[src] = true;

        // go to any nbr of that node that is not visited 
        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited, ordering);
            }
        }
        // at this point, push to the front, the particular node
        ordering.push_front(src);
        return;
    }


    void dfs(){ // Depth first search
        map<T,bool> visited;
        list<T> ordering;
        // Mark all the nodes as not visited (initially)
        for(auto p:l){
            T node = p.first;
            visited[node]= false; 
        }

        // Calling the helper function
        for(auto p:l){
            T node = p.first;
            if(!visited[node]){\
                dfs_helper(node,visited,ordering);
            }
        }

        // either return or print the list

        for(auto node:ordering){
            cout<<node<<endl;
        }
    }
};

int main(){

    Graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecogn");
    g.addEdge("DataSet","FaceRecogn");

    g.dfs();
    return 0;
}