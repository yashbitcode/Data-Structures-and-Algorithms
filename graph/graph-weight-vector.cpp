#include <iostream>
#include <vector>
using namespace std;

class GraphWeightedVector {
private:
    vector<vector<pair<int, int>>> graph;
    int length;
    bool isDirected;

public:
    GraphWeightedVector(int length = 1, bool isDirected = true) {
        int baseLen = length <= 0 ? 1 : length;
        graph = vector<vector<pair<int, int>>>(baseLen);

        this->length = baseLen;
        this->isDirected = isDirected;
    }

    void addEdge(int src, int dest, int weight) {
        if(src >= length || src < 0) {
            cout << "Invalid source" << endl;
            return;
        }
        if(dest >= length || dest < 0) {
            cout << "Invalid dest." << endl;
            return;
        }

        graph[src].push_back({dest, weight});

        if(!isDirected) graph[dest].push_back({src, weight});
    }

    void printGraph() {
        for(int i = 0; i < length; i++) {
            cout << i << " : ";

            for(auto it: graph[i]) {
                cout << "(" << it.first << ", "<< it.second << ") ";
            } 

            cout << endl;
        }
    }
};

int main() {
    GraphWeightedVector gr(4, false);

    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 2, 9);
    gr.addEdge(0, 3, 7);
    gr.addEdge(1, 3, 12);
    gr.addEdge(1, 2, 87);
    gr.addEdge(2, 3, 2);

    gr.printGraph();

    vector<int> v;

    v.push_back(90);
    v.push_back(10);
    v.push_back(20);

    cout << v.size() << endl;
}