class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& u, vector<int>& v) {
        int n = u.size();
        int m = v.size();
        vector<int> f(n + 1, 0);
        vector<int> ans;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (++f[u[i]] == 2) {
                c++;
            }
            if (++f[v[i]] == 2) {
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};