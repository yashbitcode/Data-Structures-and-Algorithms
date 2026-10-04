#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class GraphMap
{
private:
    unordered_map<int, vector<int>> adj;
    bool isDirected;

    bool doesKeyExist(int val) {
        return adj.find(val) != adj.end();
    }

    int getPosition(const vector<int>& vec, int val) {
        int cnt = 0;

        for(int i = 0; i < vec.size(); i++) {
            if(vec[cnt] == val) break;
            cnt++; 
        }

        return cnt == vec.size() ? -1 : cnt;
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

        adj[src].push_back(dest);

        if (!isDirected)
            adj[dest].push_back(src);
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

        vector<int>& srcVec = adj[src];
        vector<int>& destVec = adj[dest];

        int srcCnt = getPosition(srcVec, dest);
        int destCnt = getPosition(destVec, src);

        if(srcCnt == -1) {
            cout << "Edge doesn't exist" << endl;
            return;
        }
        if(!isDirected && destCnt == -1) {
            cout << "Edge doesn't exist" << endl;
            return;
        }

        srcVec.erase(srcVec.begin() + srcCnt, srcVec.begin() + srcCnt + 1);

        if(!isDirected) destVec.erase(destVec.begin() + destCnt, destVec.begin() + destCnt + 1);
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
    // GraphMap directedGr(true);
    // directedGr.addEdge(1, 3);
    // directedGr.addEdge(2, 4);
    // directedGr.addEdge(2, 3);
    // directedGr.addEdge(3, 5);
    // directedGr.addEdge(4, 5);

    // directedGr.deleteEdge(1, 3);
    // directedGr.deleteEdge(2, 3);
    
    // directedGr.printGraph();
    
    GraphMap undirectedGr;
    undirectedGr.addEdge(1, 3);
    undirectedGr.addEdge(2, 4);
    undirectedGr.addEdge(2, 3);
    undirectedGr.addEdge(3, 5);
    undirectedGr.addEdge(4, 5);

    undirectedGr.deleteEdge(2, 3);

    undirectedGr.printGraph();

    cout << endl << endl;   
}