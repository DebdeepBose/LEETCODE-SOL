class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edge) {
        vector<vector<int>> adj(V);
        for (auto e : edge) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> indegree(V);
        queue<int> q;
     

        for (int i = 0; i < V; i++) {
            for (auto e : adj[i]) {
                indegree[e]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int c = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            c++;

            for (auto e : adj[node]) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    q.push(e);
                }
            }
        }

        return c == V;
    }
};