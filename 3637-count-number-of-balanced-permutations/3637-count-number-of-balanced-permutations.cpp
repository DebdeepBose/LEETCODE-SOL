class Solution {
public:
    const int MOD = 1'000'000'007;
    vector<long long> fact, invFact;
    vector<int> ctr;
    int odd_cnt, evn_cnt, odd_target;
    unordered_map<long long, long long> memo;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long dp(int odd_digits, int evn_digits, int odd_sum, int digit) {
        if (digit > 9) {
            return ((odd_sum == odd_target) && (odd_digits == odd_cnt)) ? 1 : 0;
        }
        long long key = (((((long long)odd_digits << 10) + evn_digits) << 12) + odd_sum) << 6 | digit;
        if (memo.count(key)) {
            return memo[key];
        }
        long long res = 0;
        for (int odd_add = 0; odd_add <= ctr[digit]; odd_add++) {
            int evn_add = ctr[digit] - odd_add;
            if (odd_sum + digit * odd_add > odd_target) continue;
            if (odd_digits + odd_add > odd_cnt) continue;
            if (evn_digits + evn_add > evn_cnt) continue;
            long long ways = dp(odd_digits + odd_add, evn_digits + evn_add, odd_sum + digit * odd_add, digit + 1);
            ways = ways * comb(odd_cnt - odd_digits, odd_add) % MOD;
            ways = ways * comb(evn_cnt - evn_digits, evn_add) % MOD;
            res = (res + ways) % MOD;
        }
        return memo[key] = res;
    }

    int countBalancedPermutations(string num) {
        int sm = 0;
        ctr.assign(10, 0);
        for (char c : num) {
            int d = c - '0';
            sm += d;
            ctr[d]++;
        }
        if (sm % 2) return 0;
        odd_cnt = num.size() / 2;
        evn_cnt = (num.size() + 1) / 2;
        odd_target = sm / 2;
        int n = num.size();
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
        memo.clear();
        return dp(0, 0, 0, 0);
    }
};
