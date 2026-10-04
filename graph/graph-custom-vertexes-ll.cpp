#include <iostream>
using namespace std;

class Graph
{
private:
    struct EdgeConnection;
    struct Vertex;

    Vertex* head;

    struct Vertex
    {
        char id;
        EdgeConnection *edges;
        Vertex* next;

        Vertex(char id, Vertex* next = nullptr, EdgeConnection* edges = nullptr): id(id), next(next), edges(edges) {}
    };

    struct EdgeConnection
    {
        Vertex *vertex;
        EdgeConnection *next;

        EdgeConnection(Vertex* vertex, EdgeConnection* next = nullptr): vertex(vertex), next(next) {}
    };

public:
    Graph() {
        head = nullptr;
    }

    void addVertex(char vertexId) {
        Vertex* temp = head;
        Vertex* newVertex = new Vertex(vertexId);

        if(!temp) {
            head = newVertex;
            return;
        }

        while(temp->next) {
            temp = temp->next;
        } 

        temp->next = newVertex;
    } 

    void addEdge(int src, int dest) {
        Vertex* temp = head;
        Vertex* srcNode = nullptr;
        Vertex* destNode = nullptr;
        
        while(temp && (!srcNode || !destNode)) {
            if(temp->id == src) srcNode = temp;
            if(temp->id == dest) destNode = temp;

            temp = temp->next;
        }

        if(!srcNode) {
            cout << "Invalid source" << endl;
            return;
        }

        if(!destNode) {
            cout << "Invalid dest." << endl;
            return;
        }

        EdgeConnection* vertexEdges = srcNode->edges;
        
        EdgeConnection* destEdge = new EdgeConnection(destNode);

        if(!vertexEdges) {
            srcNode->edges = destEdge;
            return;
        }

        while(vertexEdges->next) {
            vertexEdges = vertexEdges->next;
        }

        vertexEdges->next = destEdge;
    }
    
    void printAllVertexes() {
        Vertex* temp = head;

        cout << "VERTEXES: ";

        while(temp) {
            cout << temp->id << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void printGraph() {
        Vertex* temp = head;

        while(temp) {
            EdgeConnection* edges = temp->edges;

            cout << temp->id << ": ";

            while(edges) {
                cout << edges->vertex->id << ' ';
                edges = edges->next;
            }

            temp = temp->next;

            cout << endl;
        }
    }
};

int main() {
    Graph gr;

    cout << (0 || 19) << endl;

    // gr.printAllVertexes();

    // gr.addVertex('A');
    // gr.addVertex('B');
    // gr.addVertex('C');
    // gr.addVertex('D');

    // gr.printAllVertexes();

    // gr.addEdge('A', 'B');
    // gr.addEdge('A', 'C');
    // gr.addEdge('B', 'A');
    // gr.addEdge('C', 'B');
    // gr.addEdge('C', 'A');
    // gr.addEdge('C', 'D');
    // gr.addEdge('D', 'C');
    // gr.addEdge('D', 'B');
    // gr.addEdge('D', 'A');

    // gr.addEdge('A', 'B');
    // gr.addEdge('B', 'A');
    // gr.addEdge('B', 'C');
    // gr.addEdge('B', 'D');

    // gr.printGraph();
}