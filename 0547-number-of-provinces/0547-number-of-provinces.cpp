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

        vector<int> vis(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int ne : adj[node]) {
                        if (!vis[ne]) {
                            vis[ne] = 1;
                            q.push(ne);
                        }
                    }
                }
            }
        }

        return count;
    }
};
