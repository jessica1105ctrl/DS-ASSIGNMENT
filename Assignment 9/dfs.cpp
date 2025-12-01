
#include <iostream>
using namespace std;

const int MAX = 50;
int n;
int adj[MAX][MAX];

void DFS(int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, visited);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 = no edge, 1 = edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex (0 to " << n-1 << "): ";
    cin >> start;

    bool visited[MAX] = {false};
    cout << "DFS Traversal: ";
    DFS(start, visited);
    cout << endl;

    return 0;
}
