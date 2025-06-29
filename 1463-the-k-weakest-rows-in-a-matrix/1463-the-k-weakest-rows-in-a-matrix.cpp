class Solution {
public:
    typedef pair<int, int> p;
    vector<int> kWeakestRows(vector<vector<int>>& v, int k) {
        priority_queue<p> pq;
        int n = v.size();
        int m = v[0].size();
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    c++;
                } else {
                    break;
                }
            }
            pq.push({c, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};