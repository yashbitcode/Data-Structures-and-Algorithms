#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<char> vertexes;
    vector<vector<pair<int, int>>> graph;
    bool isDirected;

public:
    Graph(bool isDirected = true) {
        this->isDirected = isDirected;
    }

    void addVertex(char vertex) {
        vertexes.push_back(vertex);
        graph.push_back({});
    }

    void addEdge(int src, int dest, int weight = 0) {
        if(src >= vertexes.size() || src < 0) {
            cout << "Invalid source" << endl;
            return;
        }
        if(dest >= vertexes.size() || dest < 0) {
            cout << "Invalid dest." << endl;
            return;
        }

        graph[src].push_back({dest, weight});

        if(!isDirected) graph[dest].push_back({src, weight});
    }

    void printGraph() {
        for(int i = 0; i < vertexes.size(); i++) {
            cout << vertexes[i] << " : ";

            for(auto it: graph[i]) {
                cout << "(" << vertexes[it.first] << ", "<< it.second << ") ";
                // cout << vertexes[it.first] << " ";
            } 

            cout << endl;
        }
    }
};

int main() {    
    // Graph gr;
    // gr.addVertex('A');
    // gr.addVertex('B');
    // gr.addVertex('C');
    // gr.addVertex('D');

    // gr.addEdge(0, 2);
    // gr.addEdge(1, 0);
    // gr.addEdge(1, 2);
    // gr.addEdge(1, 3);
    // gr.addEdge(2, 1);
    // gr.addEdge(3, 2);
    // gr.addEdge(3, 1);

    // gr.printGraph();
    
    Graph gr(false);
    gr.addVertex('A');
    gr.addVertex('B');
    gr.addVertex('C');
    gr.addVertex('D');

   gr.addEdge(0, 1, 12);
   gr.addEdge(0, 2, 9);
   gr.addEdge(0, 3, 1);
   gr.addEdge(1, 2, 78);
   gr.addEdge(1, 3, 23);
   gr.addEdge(2, 3, 20);

    gr.printGraph();

    // gr.addEdge(0, 1, 10);
    // gr.addEdge(0, 2, 9);
    // gr.addEdge(0, 3, 7);
    // gr.addEdge(1, 3, 12);
    // gr.addEdge(1, 2, 87);
    // gr.addEdge(2, 3, 2);

    // gr.printGraph();

    // vector<int> v;

    // v.push_back(90);
    // v.push_back(10);
    // v.push_back(20);

    // cout << v.size() << endl;
}