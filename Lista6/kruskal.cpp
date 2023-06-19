#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

typedef vector<Edge> EdgeList;
typedef vector<int> Subset;

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int find(Subset& subsets, int i) {
    if (subsets[i] == -1)
        return i;
    return find(subsets, subsets[i]);
}

void unionSets(Subset& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    subsets[xroot] = yroot;
}

vector<Edge> kruskalMST(const EdgeList& edges, int numVertices) {
    vector<Edge> mst;
    Subset subsets(numVertices, -1);

    EdgeList sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    for (const auto& edge : sortedEdges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        int uroot = find(subsets, u);
        int vroot = find(subsets, v);

        if (uroot != vroot) {
            mst.push_back(edge);
            unionSets(subsets, uroot, vroot);
        }
    }

    return mst;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    EdgeList edges;
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }

    vector<Edge> minimumSpanningTree = kruskalMST(edges, numVertices);

    for (const auto& edge : minimumSpanningTree) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
