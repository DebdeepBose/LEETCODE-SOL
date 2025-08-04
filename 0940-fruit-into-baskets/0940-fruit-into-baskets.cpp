class Solution {
public:
    int totalFruit(vector<int>& v) {
        int n = v.size();
        if (n == 1) {
            return n;
        }
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int maxf = -1;
        while (r < n) {
            mp[v[r]]++;
            if (mp.size() == 2) {
                int f = 0;
                for (auto e : mp) {
                    f += e.second;
                }
                maxf = max(maxf, f);
            }
            if (mp.size() > 2) {
                mp[v[l]]--;
                if (mp[v[l]] == 0) {
                    mp.erase(v[l]);
                }
                l++;
            }
            r++;
        }
        if (maxf == -1) {
            return mp[v[0]];
        }
        else{
            return maxf;
        }
    }
};