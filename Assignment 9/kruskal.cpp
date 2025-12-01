
#include <iostream>
using namespace std;

const int MAX = 50;
const int INF = 999999;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findParent(parent, parent[i]); 
}

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

    // build edge list (upper triangle of matrix)
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = adj[i][j];
                edgeCount++;
            }
        }
    }

    // sort edges by weight (simple bubble sort)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Edges in Kruskal's MST:\n";
    int mstWeight = 0;
    int used = 0;

    for (int i = 0; i < edgeCount && used < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {
            cout << u << " -- " << v << "  weight = " << w << endl;
            mstWeight += w;
            parent[pu] = pv;   // union
            used++;
        }
    }

    cout << "Total weight of MST = " << mstWeight << endl;
    return 0;
}
