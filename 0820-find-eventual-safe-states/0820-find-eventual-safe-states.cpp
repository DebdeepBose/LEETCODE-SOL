class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        vector<int> check(V, -1);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, path, adj, check);
            }
        }

        vector<int> safe;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safe.push_back(i);
            }
        }

        return safe;
    }

    bool dfs(int node, vector<int>& vis, vector<int>& path,
             vector<vector<int>>& adj, vector<int>& check) {
        vis[node] = 1;
        path[node] = 1;

        for (auto e : adj[node]) {
            if (!vis[e]) {
                if (dfs(e, vis, path, adj, check)) {
                    check[node] = 0;
                    path[node] = 0;
                    return true;
                }
            } else {
                if (path[e]) {
                    check[node] = 0;
                    path[node] = 0;
                    return true;
                }
                if (check[e] == 0) {
                    check[node] = 0;
                    path[node] = 0;
                    return true;
                }
            }
        }

        check[node] = 1;
        path[node] = 0;
        return false;
    }
};
