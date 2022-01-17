#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    unordered_map<T, list<pair<T, int>>> m;

    public: 

    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj(){
        // printing Adj list
        // iterate over all key value pairs in the map

        for(auto j:m){

            cout<<j.first<<" -> ";

            // iterate over the list of cities
            for(auto l: j.second){
                cout<<"( "<<l.first<<","<<l.second<<" )";
            }
            cout<<endl;
        }
    }

    void dijsktraAlgo(T src){
        unordered_map<T, int> dist;

        // set all dist to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }

        // Make a set to find out node with min distance
        set<pair<int, T>> s;

        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){

            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //Iterate over the neighbours/children of the current node
            for(auto childPair: m[node]){

                if(nodeDist + childPair.second < dist[childPair.first]){


                    // In the set, updation of a particular node is not possible
                    // we have to remove the old pair and insert the new pair to stimulate updation
                    T dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest], dest));

                    if(f!=s.end()){
                        s.erase(f);
                    }

                    // Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));

                }
            }
        }
        // Let's print distances to all other nodes from src
        for( auto d: dist){
            cout<<d.first<<" is located at: "<<d.second<<" distance from the source. "<<endl;
        }
    }
};

int main() {

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    // g.printAdj();
    g.dijsktraAlgo(1);

    // Graph<string> india;
    // india.addEdge("Amritsar", "Delhi", 1);
    // india.addEdge("Amritsar", "Jaipur", 4);
    // india.addEdge("Jaipur", "Delhi", 2);
    // india.addEdge("Jaipur", "Mumbai", 8);
    // india.addEdge("Bhopal", "Agra", 2);
    // india.addEdge("Mumbai", "Bhopal", 3);
    // india.addEdge("Agra", "Delhi", 1);
    // india.printAdj();
    // india.dijsktraAlgo("Amritsar");

    return 0;
}
