class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> mp;
        int presum = 0;
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                presum--;
            } else {
                presum++;
            }

            if (presum == 0) {
                maxlen = i + 1;
            } else if (mp.find(presum) != mp.end()) {
                maxlen = max(maxlen, i - mp[presum]);
            } else {
                mp[presum] = i;
            }
        }
        return maxlen;
    }
};
