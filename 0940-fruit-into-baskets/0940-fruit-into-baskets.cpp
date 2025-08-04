class Solution {
public:
    int totalFruit(vector<int>& v) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, n = v.size();
        int maxf = 0;

        while (r < n) {
            mp[v[r]]++;

            while (mp.size() > 2) {
                mp[v[l]]--;
                if (mp[v[l]] == 0) {
                    mp.erase(v[l]);
                }
                l++;
            }

            maxf = max(maxf, r - l + 1);
            r++;
        }

        return maxf;
    }
};
