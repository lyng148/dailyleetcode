class Graph {
    static constexpr int kMaxN = 100;
    static constexpr int kMaxEdgeCost = 1'000'000;
    static constexpr int kNoPathCost = (kMaxN - 1) * kMaxEdgeCost + 1;
public:
    Graph(int n, const vector<vector<int>>& edges) : dist(n, vector<int>(n, kNoPathCost)) {
        for (auto& edge : edges) dist[edge[0]][edge[1]] = edge[2];
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
   
    void addEdge(const vector<int>& edge) {
        if (dist[edge[0]][edge[1]] <= edge[2]) return;
        for (int i = 0, n = dist.size(); i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + dist[edge[1]][j] + edge[2]);
    }
   
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] != kNoPathCost ? dist[node1][node2] : -1;
    }

private:
    vector<vector<int>> dist;
};