class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, int> mp;
        int n = b1.size();

        for (int i = 0; i < n; i++) {
            mp[b1[i]]++;
            mp[b2[i]]--;
        }

        vector<int> extra1, extra2;

        for (auto e : mp) {
            if (e.second % 2 != 0) {
                return -1;
            }
            if (e.second > 0) {
                for (int i = 0; i < e.second / 2; i++) {
                    extra1.push_back(e.first);
                }
            } else if (e.second < 0) {
                for (int i = 0; i < (-e.second) / 2; i++) {
                    extra2.push_back(e.first);
                }
            }
        }

        if (extra1.empty()) {
            return 0;
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        int smallest = mp.begin()->first;
        long long ans = 0;

        for (int i = 0; i < extra1.size(); i++) {
            if (2LL * smallest < 1LL * min(extra1[i], extra2[i])) {
                ans += 2LL * smallest;
            } else {
                ans += 1LL * min(extra1[i], extra2[i]);
            }
        }

        return ans;
    }
};
