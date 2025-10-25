class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto e : edges) {
            adj[e[1]].push_back(e[0]);
        }

        vector<int> topo;
        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, st, vis, adj) == false) {
                    return {};
                }
            }
        }

        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo.size() == V ? topo : vector<int>();
    }
    bool dfs(int node, stack<int>& st, vector<int>& vis,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto nei : adj[node]) {
            if (vis[nei] == 0) {
                if (dfs(nei, st, vis, adj) == false)
                    return false;
            } else if (vis[nei] == 1) {
                return false;
            }
        }
        vis[node] = 2;
        st.push(node);
        return true;
    }
};