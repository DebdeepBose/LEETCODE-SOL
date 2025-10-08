class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int m = adj.size();
        vector<int> color(m, -1);

        for (int start = 0; start < m; start++) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto e : adj[node]) {
                        if (color[e] == -1) {
                            color[e] = !color[node];
                            q.push(e);
                        } else if (color[e] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
