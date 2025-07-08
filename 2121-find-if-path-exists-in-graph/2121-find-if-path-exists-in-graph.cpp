class Solution {
public:
    bool validPath(int n, vector<vector<int>>& ed, int source, int dest) {
        vector<vector<int>> adj(n);
        for (auto e : ed) {
            int f = e[0];
            int s = e[1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) {
                return true;
            }

            for (auto e : adj[node]) {
                if (!vis[e]) {
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
        return false;
    }
};