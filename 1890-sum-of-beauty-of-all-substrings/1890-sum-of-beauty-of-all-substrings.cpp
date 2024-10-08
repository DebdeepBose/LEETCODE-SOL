class Solution {
public:
    int mpmax(vector<int>& mp) {
        int mapmx = INT_MIN;
        for (int freq : mp) {
            mapmx = max(mapmx, freq);
        }
        return mapmx;
    }
    int mpmin(vector<int>& mp) {
        int mapmn = INT_MAX;
        for (int freq : mp) {
            if (freq > 0) {
                mapmn = min(mapmn, freq);
            }
        }
        return mapmn;
    }
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();
        for (int l = 0; l < n; l++) {
            vector<int> mp(26, 0);
            for (int r = l; r < n; r++) {
                mp[s[r] - 'a']++;
                if (r - l + 1 > 1) {
                    int beauty = mpmax(mp) - mpmin(mp);
                    sum += beauty;
                }
            }
        }
        return sum;
    }
};
