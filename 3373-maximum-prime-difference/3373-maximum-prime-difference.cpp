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
        vector<bool> p = sieve(101);
        int firstPrime = -1, lastPrime = -1;

        for (int i = 0; i < v.size(); i++) {
            if (p[v[i]]) {
                if (firstPrime == -1) {
                    firstPrime = i;
                }
                lastPrime = i;
            }
        }

        if (firstPrime == -1 || lastPrime == -1) {
            return 0;
        }

        return lastPrime - firstPrime;
    }
};