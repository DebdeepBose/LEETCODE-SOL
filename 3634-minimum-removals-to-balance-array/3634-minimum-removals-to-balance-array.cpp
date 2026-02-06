class Solution {
public:
    int minRemoval(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(), v.end());
        int mx = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            while ((long long)v[j] > (long long)v[i] * k) {
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        return n - mx;
    }
};