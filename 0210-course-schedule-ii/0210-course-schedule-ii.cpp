class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto e : edges) {
            adj[e[1]].push_back(e[0]);
        }

        vector<int> topo;
        stack<int> st;
        vector<bool> vis(V);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, st, vis, adj);
            }
        }

        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
    void dfs(int node, stack<int>& st, vector<bool>& vis,
             vector<vector<int>>& adj) {

        vis[node] = true;

        for (auto e : adj[node]) {
            if (!vis[e]) {
                dfs(e, st, vis, adj);
            }
        }
        st.push(node);
    }
};