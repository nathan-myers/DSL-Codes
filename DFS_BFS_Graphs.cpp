/* DFS Part is implemented successfully. BFS part is left
Implement BFS by using same adjacency 'cost' matrix but instead of stack use queue */



#include <iostream>
#include <stack>

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

    // Depth-First Search (DFS) algorithm
    void DFS(int start) {
        stack<int> s;
        bool visit[MAX_VERTICES] = {false};

        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visit[current]) {
                cout << current << " ";
                visit[current] = true;

                for (int i = V - 1; i >= 0; --i) {
                    if (cost[current][i] && !visit[i]) {
                        s.push(i);
                    }
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

    cout << "DFS Traversal starting from vertex 0: ";
    graph.DFS(0);

    return 0;
}
