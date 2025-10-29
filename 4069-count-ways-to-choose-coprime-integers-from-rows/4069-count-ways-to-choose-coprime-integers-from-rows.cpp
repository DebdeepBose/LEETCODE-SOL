class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (auto row : mat) {
            unordered_map<int, int> nxt;
            for (int a : row) {
                for (auto& p : cnt) {
                    int g = gcd(a, p.first);
                    nxt[g] = (nxt[g] + p.second) % MOD;
                }
            }
            cnt.swap(nxt);
        }
        return cnt[1];
    }
};