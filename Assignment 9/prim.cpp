
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

    int key[MAX];      // min weight to connect vertex
    int parent[MAX];   // parent of vertex in MST
    bool inMST[MAX];   // included in MST or not

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0;        // start from vertex 0
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minKey = INF;

        // pick vertex not in MST with smallest key
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        // update neighbours
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in Prim's MST:\n";
    int totalWeight = 0;
    for (int v = 1; v < n; v++) {
        cout << parent[v] << " -- " << v
             << "  weight = " << adj[parent[v]][v] << endl;
        totalWeight += adj[parent[v]][v];
    }
    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}
