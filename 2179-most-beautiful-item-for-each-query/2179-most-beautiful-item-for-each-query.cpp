class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& v, vector<int>& q) {
        int l = v.size();
        int n = q.size();
        vector<int> ans(n);

        vector<pair<int, int>> qp;
        for (int i = 0; i < n; i++) {
            qp.push_back({q[i], i});
        }

        sort(v.begin(), v.end());
        sort(qp.begin(), qp.end());

        int maxb = 0;
        int idx = 0;
        int m = qp.size();

        for (int i = 0; i < m; i++) {
            int maxi = qp[i].first;
            int ogidx = qp[i].second;

            while (idx < l && v[idx][0] <= maxi) {
                maxb = max(maxb, v[idx][1]);
                idx++;
            }
            ans[ogidx] = maxb;
        }

        return ans;
    }
};
