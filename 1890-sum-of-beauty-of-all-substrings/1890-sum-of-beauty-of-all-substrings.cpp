class Solution {
public:
    int mpmax(unordered_map<char, int>& mp) {
        int mapmx = INT_MIN;
        for (auto e : mp) {
            mapmx = max(mapmx, e.second);
        }
        return mapmx;
    }
    int mpmin(unordered_map<char, int>& mp) {
        int mapmn = INT_MAX;
        for (auto e : mp) {
            mapmn = min(mapmn, e.second);
        }
        return mapmn;
    }
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();
        for (int l = 0; l < n; l++) {
            unordered_map<char, int> mp;
            for (int r = l; r < n; r++) {
                mp[s[r]]++;
                if (mp.size() > 1) {
                    int beauty = mpmax(mp) - mpmin(mp);
                    sum += beauty;
                }
            }
        }
        return sum;
    }
};
