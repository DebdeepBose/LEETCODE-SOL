class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = col;

        for (auto e : adj[node]) {
            if (color[e] == -1) {
                if (!dfs(e, !col, adj, color)) 
                    return false;
            } 
            else if (color[e] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int m = adj.size();
        vector<int> color(m, -1);

        for (int i = 0; i < m; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};
