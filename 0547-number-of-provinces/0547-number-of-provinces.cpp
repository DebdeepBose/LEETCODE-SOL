class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto e : adj[node]) {
            if (!vis[e]) {
                dfs(e, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& v) {
        int n = v[0].size();
        vector<vector<int>> adj(n + 1); 

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == 1 && i + 1 != j + 1) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        vector<int> vis(n + 1, 0);
        int c = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, adj, vis);
            }
        }

        return c;
    }
};
