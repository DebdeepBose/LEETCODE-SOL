class Solution {
public:
    int maxScore(string s) {
        int z = 0;
        int o = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                z++;
            } else {
                o++;
            }
            if (i != s.size() - 1) {
                maxi = max(z - o, maxi);
            }
        }
        return maxi + o;
    }
};