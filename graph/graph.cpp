#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include <iostream>
#include <vector>
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

    void DFS(int root)
    {
        if (root >= size)
        {
            cout << "Invalid root" << endl;
            return;
        }

        Stack st(100);
        bool visited[size] = {false};

        st.push(root);

        while (!st.isEmpty())
        {
            int val = st.pop();

            if (!visited[val])
                cout << val << " -> ";

            visited[val] = true;

            for (int i = 0; i < size; i++)
            {
                if (matrix[val][i] && !visited[i])
                    st.push(i);
            }

            if (st.isEmpty())
                cout << "X" << endl;
        }
    }

    void DFSRecursive(vector<bool> &visited, vector<int> &res, int src)
    {
        visited[src] = true;
        res.push_back(src);

        for (int i = 0; i < size; i++)
        {
            if (matrix[src][i] && !visited[i])
                DFSRecursive(visited, res, i);
        }
    }

    void BFS(int root)
    {
        vector<bool> visited(size, false);
        Queue q(size);

        visited[root] = true;
        q.push(root);

        while (!q.isEmpty())
        {
            int val = q.pop();

            cout << val << " -> ";

            for (int i = 0; i < size; i++)
            {
                if (!visited[i] && matrix[val][i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }

            if (q.isEmpty())
                cout << "X";
        }
    }

    ~Graph()
    {
        cout << endl
             << "Graph destruction" << endl;
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

    cout << endl;

    g.DFS(0);
    g.BFS(0);
}