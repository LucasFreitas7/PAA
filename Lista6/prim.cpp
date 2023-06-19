#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

typedef vector<vector<pair<int, int>>> Graph;

vector<bool> visited;

class Compare {
public:
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

int primMST(const Graph& graph, int start) {
    int n = graph.size();
    visited.assign(n, false);

    priority_queue<Edge, vector<Edge>, Compare> pq;
    pq.push(Edge(start, start, 0));

    int totalWeight = 0;

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        int u = edge.v;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += edge.weight;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v]) {
                pq.push(Edge(u, v, weight));
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    int start;
    cin >> start;

    int minimumWeight = primMST(graph, start);
    cout << minimumWeight << endl;

    return 0;
}
