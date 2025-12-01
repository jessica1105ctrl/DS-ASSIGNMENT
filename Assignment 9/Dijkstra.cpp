
#include <iostream>
using namespace std;

const int MAX = 50;
const int INF = 999999;

int main() {
    int n;
    int adj[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter weighted adjacency matrix (0 = no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int src;
    cout << "Enter source vertex (0 to " << n-1 << "): ";
    cin >> src;

    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    // Dijkstra
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minDist = INF;

        // pick unvisited vertex with smallest distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;      
        visited[u] = true;

        // relax edges
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v] &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << endl;
    }

    return 0;
}
