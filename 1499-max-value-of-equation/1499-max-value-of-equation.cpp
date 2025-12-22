class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& v, int k) {
        priority_queue<pair<int, int>> pq;
        int n = v.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            while ((!pq.empty()) && (v[i][0] - pq.top().second) > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans = max(ans, v[i][0] + v[i][1] + pq.top().first);
            }
            pq.push({v[i][1] - v[i][0], v[i][0]});
        }
        return ans;
    }
};