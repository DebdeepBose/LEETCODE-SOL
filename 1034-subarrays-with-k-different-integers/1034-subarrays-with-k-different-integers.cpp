class Solution {
public:
    int calc(vector<int>& v, int k) {
        int l = 0;
        int r = 0;
        int c = 0;
        unordered_map<int, int> mp;
        int n = v.size();
        while (r < n) {
            mp[v[r]]++;
            while (mp.size() > k) {
                mp[v[l]]--;
                if (mp[v[l]] == 0) {
                    mp.erase(v[l]);
                }
                l++;
            }
            c += r - l + 1;
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
        return calc(v, k) - calc(v, k - 1);
    }
};