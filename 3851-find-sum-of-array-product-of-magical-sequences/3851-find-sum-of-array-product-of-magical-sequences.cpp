class Solution {
public:
    const int MOD = 1e9 + 7;
    int C[31][31];
    int dp[31][31][50][31];
    int m, k, n;

    void buildPascal() {
        memset(C, 0, sizeof(C));
        for (int i = 0; i <= 30; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    int dfs(int m, int k, int i, unsigned flag, vector<int>& v) {
        int bits = 0;
        unsigned temp = flag;
        while (temp) {
            bits += temp & 1;
            temp >>= 1;
        }

        if (m < 0 || k < 0 || m + bits < k) {
            return 0;
        }

        if (m == 0) {
            return (k == bits) ? 1 : 0;
        }

        if (i >= n) {
            return 0;
        }

        if (dp[m][k][i][flag] != -1) {
            return dp[m][k][i][flag];
        }

        long long ans = 0;
        long long powX = 1;
        int x = v[i];

        for (int f = 0; f <= m; f++) {
            long long comb = 1LL * C[m][f] * powX % MOD;
            unsigned newFlag = flag + f;
            unsigned nextFlag = newFlag >> 1;
            bool bitSet = newFlag & 1;

            ans = (ans + comb * dfs(m - f, k - bitSet, i + 1, nextFlag, v)) % MOD;

            powX = powX * x % MOD;
        }

        dp[m][k][i][flag] = ans;
        return ans;
    }

    int magicalSum(int m, int k, vector<int>& v) {
        buildPascal();
        this->m = m;
        this->k = k;
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return dfs(m, k, 0, 0, v);
    }
};
