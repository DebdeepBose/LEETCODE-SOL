class Solution {
public:
    int maxLength(vector<int>& v) {
        int ans = 2;
        for (int i = 0; i < v.size() - 1; i++) {
            int gcd = v[i];
            int lcm = v[i];

            for (int j = i + 1; j < v.size(); j++) {
                gcd = __gcd(gcd, v[j]);

                int gcd2 = __gcd(lcm, v[j]);
                lcm = (lcm / gcd2) * v[j];

                if (gcd != 1 || gcd2 != 1) {
                    break;
                }

                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};