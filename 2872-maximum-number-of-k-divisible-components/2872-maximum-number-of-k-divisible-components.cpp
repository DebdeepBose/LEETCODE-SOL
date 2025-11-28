class Solution {
public:
    void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& parent,
             stack<int>& st) {
        parent[u] = p;
        st.push(u);

        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, adj, parent, st);
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n);
        stack<int> st;

        dfs(0, -1, adj, parent, st);

        vector<long long> sum(n);
        for (int i = 0; i < n; i++) {
            sum[i] = values[i];
        }

        int ans = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (sum[u] % k == 0) {
                ans++;
            } else {
                sum[parent[u]] += sum[u];
            }
        }

        return ans;
    }
};
