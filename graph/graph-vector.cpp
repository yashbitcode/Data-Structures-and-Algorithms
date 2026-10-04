#include <iostream>
#include <vector>
using namespace std;

class GraphVector {
private:
    vector<vector<int>> graph;
    int length;
    bool isDirected;

public:
    GraphVector(int length = 1, bool isDirected = true) {
        int baseLen = length <= 0 ? 1 : length;
        graph = vector<vector<int>>(baseLen);

        this->length = baseLen;
        this->isDirected = isDirected;
    }

    void addEdge(int src, int dest) {
        if(src >= length || src < 0) {
            cout << "Invalid source" << endl;
            return;
        }
        if(dest >= length || dest < 0) {
            cout << "Invalid dest." << endl;
            return;
        }

        graph[src].push_back(dest);

        if(!isDirected) graph[dest].push_back(src);
    }

    void printGraph() {
        for(int i = 0; i < length; i++) {
            cout << i << " : ";

            for(auto it: graph[i]) {
                cout << it << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    GraphVector gr(4, false);

    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(0, 3);
    gr.addEdge(1, 3);
    gr.addEdge(1, 2);
    gr.addEdge(2, 3);

    gr.printGraph();
}