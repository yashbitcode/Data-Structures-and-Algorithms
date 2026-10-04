#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class GraphMap
{
private:
    unordered_map<int, set<int>> adj;
    bool isDirected;

    bool doesKeyExist(int val) {
        return adj.find(val) != adj.end();
    }
public:
    GraphMap(bool isDirected = false) {
        this->isDirected = isDirected;
    }

    void addEdge(int src, int dest)
    {
        if (!doesKeyExist(src))
            adj[src] = {};
        if (!doesKeyExist(dest))
            adj[dest] = {};

        adj[src].insert(dest);

        if (!isDirected)
            adj[dest].insert(src);
    }

    void deleteEdge(int src, int dest) {
        if (!doesKeyExist(src)) {
            cout << "Invalid source" << endl;
            return;
        }
        if (!doesKeyExist(dest)) {
            cout << "Invalid dest." << endl;
            return;
        }

        set<int>& srcSet = adj[src];
        set<int>& destSet = adj[dest];

        auto destIt = srcSet.find(dest);
        auto srcIt = destSet.find(src);

        if(destIt == srcSet.end()) {
            cout << "Edge doesn't exist" << endl;
            return;
        }
        if(!isDirected && srcIt == destSet.end()) {
            cout << "Edge doesn't exist" << endl;
            return;
        }

        srcSet.erase(destIt);
         if(!isDirected) destSet.erase(srcIt);
    }

    void printGraph()
    {
        for (const auto &it : adj)
        {
            cout << "VERTEX: " << it.first << " -> ";

            for (const int &neighbour : it.second)
            {
                cout << neighbour << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    GraphMap directedGr(true);
    directedGr.addEdge(1, 3);
    directedGr.addEdge(2, 4);
    directedGr.addEdge(2, 3);
    directedGr.addEdge(3, 5);
    directedGr.addEdge(4, 5);

    directedGr.deleteEdge(1, 3);
    directedGr.deleteEdge(2, 3);
    
    directedGr.printGraph();
    
//     GraphMap undirectedGr;
//     undirectedGr.addEdge(1, 3);
//     undirectedGr.addEdge(2, 4);
//     undirectedGr.addEdge(2, 3);
//     undirectedGr.addEdge(3, 5);
//     undirectedGr.addEdge(4, 5);

//     undirectedGr.deleteEdge(3, 2);

//     undirectedGr.printGraph();

//     cout << endl << endl;   
}