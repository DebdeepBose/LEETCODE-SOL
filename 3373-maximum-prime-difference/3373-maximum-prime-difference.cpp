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
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (p[v[i]] && p[v[j]]) {
                return j - i;
            } else if (p[v[i]]) {
                j--;
            } else if (p[v[j]]) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return 0;
    }
};
