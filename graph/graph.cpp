#include <iostream>
using namespace std;

class Graph
{
private:
    int **matrix;
    int size;

public:
    Graph(int vertexes)
    {
        int normalisedSize = vertexes <= 0 ? 1 : vertexes;
        size = normalisedSize;

        matrix = new int *[normalisedSize];

        for (int i = 0; i < normalisedSize; i++)
        {
            matrix[i] = new int[normalisedSize]();
        }
    }

    void addEdge(int src, int dest, int weight = 1)
    {
        if (src >= size || src < 0)
        {
            cout << "Invalid source" << endl;
            return;
        }

        if (dest >= size || dest < 0)
        {
            cout << "Invalid dest." << endl;
            return;
        }

        matrix[src][dest] = weight;
    }

    void printMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~Graph()
    {
        cout << endl << "Graph destruction" << endl;
        for (int i = 0; i < size; ++i)
        {
            delete[] matrix[i]; 
        }
        delete[] matrix;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 90);
    g.addEdge(1, 2, 10);
    // g.addEdge(200, 1);
    // g.addEdge(2, 399);
    g.addEdge(3, 0, 82);
    g.addEdge(0, 2, 67);

    g.printMatrix();
}