class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n = v.size();
        if (n == 1) {
            return 0;
        }
        int psum = 0;
        int maxlen = 0;
        int r = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        while (r < n) {
            if (v[r] == 0) {
                psum--;
            } else {
                psum++;
            }
            if (mp.find(psum) != mp.end()) {
                maxlen = max(maxlen, r - mp[psum]);
            } else {
                mp[psum] = r;
            }
            r++;
        }
        return maxlen;
    }
};