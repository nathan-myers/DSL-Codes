// Merge this with DFS_Graphs.cpp


#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int V; // Number of vertices
    int cost[MAX_VERTICES][MAX_VERTICES]; // Cost matrix for adjacency matrix representation

public:
    Graph(int V) : V(V) {
        // Initialize cost matrix with 0s
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cost[i][j] = 0;
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        cost[v][w] = 1;
        cost[w][v] = 1; // Assuming undirected graph
    }

    // Breadth-First Search (BFS) algorithm
    void BFS(int start) {
        queue<int> q;
        bool visited[MAX_VERTICES] = {false};

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < V; ++i) {
                if (cost[current][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    cout << "BFS Traversal starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}

/* 

Sample Input and Output:

Enter the number of vertices: 5
Enter the number of edges: 5
Enter the edges (vertex pairs):
0 1 
1 2
2 3
3 4
4 0
BFS Traversal starting from vertex 0: 0 1 4 2 3

*/
