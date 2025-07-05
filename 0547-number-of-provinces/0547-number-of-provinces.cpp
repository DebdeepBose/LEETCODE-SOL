class Solution {
public:
    void dfs(int node, vector<vector<int>>& v, vector<int>& vis) {
        vis[node] = 1;
        int n = v.size();
        for (int j = 1; j <= n; j++) {
            if (v[node - 1][j - 1] == 1 && !vis[j]) {
                dfs(j, v, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> vis(n + 1, 0); 
        int c = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, v, vis);
            }
        }

        return c;
    }
};
