class Solution {
public:
    int n;
    int dp[102][102];

    int solve(int ind, int prev, vector<string> &a) {
        if (ind == n) {
            return 0;
        }

        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        if (prev == -1) {
            return dp[ind][prev + 1] =
                min(
                    solve(ind + 1, ind, a),
                    1 + solve(ind + 1, prev, a)
                );
        }

        bool ok = true;
        for (int r = 0; r < (int)a.size(); r++) {
            if (a[r][prev] > a[r][ind]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return dp[ind][prev + 1] =
                min(
                    solve(ind + 1, ind, a),
                    1 + solve(ind + 1, prev, a)
                );
        }

        return dp[ind][prev + 1] = 1 + solve(ind + 1, prev, a);
    }

    int minDeletionSize(vector<string>& a) {
        n = a[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, a);
    }
};
