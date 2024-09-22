class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> p(n + 1, true);
        p[0] = p[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (p[i]) {
                for (int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
        return p;
    }

    int maximumPrimeDifference(vector<int>& v) {
        int n = v.size();
        vector<bool> p = sieve(101);
        int ans = 0;
        int firstP = -1, j = 0;
        while (j < n) {
            if (p[v[j]]) {
                if (firstP != -1) {
                    ans = j - firstP;
                } else {
                    firstP = j;
                }
            }
            j++;
        }
        return ans;
    }
};