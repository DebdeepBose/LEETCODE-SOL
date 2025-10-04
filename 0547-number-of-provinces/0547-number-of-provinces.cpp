class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int V = v.size();
        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (v[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c = 0;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, adj, vis);
            }
        }

        return c;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto e : adj[node]) {
            if (!vis[e]) {
                dfs(e, adj, vis);
            }
        }
    }
};