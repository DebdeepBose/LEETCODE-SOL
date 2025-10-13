class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& v) {
        vector<vector<int>> adj(V);
        for (auto e : v) {
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

        vector<int> topo;

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for (auto e : adj[front]) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    q.push(e);
                }
            }
        }

        return topo.size() == V;
    }
};