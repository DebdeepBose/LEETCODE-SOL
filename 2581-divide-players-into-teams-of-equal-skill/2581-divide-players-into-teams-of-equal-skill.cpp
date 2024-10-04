class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        unordered_map<int, int> mp;
        int n = v.size();
        int vsum = accumulate(v.begin(), v.end(), 0);
        long long partsum = vsum / (n / 2);

        if (partsum * (n / 2) != vsum) {
            return -1;
        }

        long long prodsum = 0;
        for (int i = 0; i < n; i++) {
            int req = partsum - v[i];
            if (mp[req] > 0) {
                prodsum += req * v[i];
                mp[req]--;
            } else {
                mp[v[i]]++;
            }
        }

        for (auto e : mp) {
            if (e.second > 0) {
                return -1;
            }
        }

        return prodsum;
    }
};
