class Solution {
public:
    int maxCapacity(vector<int>& c, vector<int>& cap, int k) {
        int n = c.size();
        int maxi = 0;
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({c[i], cap[i]});
        }

        sort(v.begin(), v.end());

        vector<int> p(n);
        int m = 0;
        int j = n - 1;

        for (int i = 0; i < n; i++) {
            int cost = v[i].first;
            int val = v[i].second;

            m = max(m, val);
            p[i] = m;

            if (cost < k) {
                maxi = max(maxi, val);
            }

            while (j >= 0 && v[j].first + cost >= k) {
                j--;
            }

            int idx = min(j, i - 1);
            if (idx >= 0) {
                maxi = max(maxi, val + p[idx]);
            }
        }

        return maxi;
    }
};
