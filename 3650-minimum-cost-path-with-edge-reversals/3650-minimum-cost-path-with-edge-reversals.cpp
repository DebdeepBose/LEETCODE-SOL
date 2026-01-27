class Solution {
public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& d) {
        vector<bool> vis(n, false);
        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            for (auto [v, w] : d[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> d(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            d[u].push_back({v, w});
            d[v].push_back({u, 2 * w});
        }

        return dijkstra(n, d);
    }
};