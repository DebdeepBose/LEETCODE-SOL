class Solution {
public:
    int findContentChildren(vector<int>& v, vector<int>& a) {
        sort(v.begin(), v.end());
        sort(a.begin(), a.end());
        int m = v.size();
        int n = a.size();
        int ans = 0;
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && a[j] < v[i]) {
                j++;
            }
            if (j < n && i < m && a[j] >= v[i]) {
                ans++;
                j++;
            }
        }
        return ans;
    }
};