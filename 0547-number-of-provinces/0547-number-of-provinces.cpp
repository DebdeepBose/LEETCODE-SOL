class Solution {
public:
    void dfs(int node, vector<vector<int>>& v, vector<int>& vis) {
        vis[node] = 1;
        for (int j = 0; j < v.size(); j++) {
            if (v[node][j] == 1 && !vis[j]) {
                dfs(j, v, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> vis(n, 0);
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, v, vis);
            }
        }

        return c;
    }
};
