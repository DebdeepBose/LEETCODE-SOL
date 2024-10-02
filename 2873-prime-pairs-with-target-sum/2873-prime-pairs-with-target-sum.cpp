class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    vector<vector<int>> findPrimePairs(int n) {
        if (n <= 3) {
            return {};
        }
        vector<vector<int>> ans;
        vector<bool> isPrime = sieve(n);
        int l = 2;
        int r = n - 2;

        while (l <= r) {
            if (isPrime[l] && isPrime[r]) {
                if (l + r == n) {
                    ans.push_back({l, r});
                    l++;
                    r--;
                } else if (l + r < n) {
                    l++;
                } else {
                    r--;
                }
            } else if (!isPrime[l] && isPrime[r]) {
                l++;
            } else if (isPrime[l] && !isPrime[r]) {
                r--;
            } else {
                l++;
                r--;
            }
        }

        return ans;
    }
};
