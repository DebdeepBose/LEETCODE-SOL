class Solution {
public:
    int maxEvents(vector<vector<int>>& v) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(), v.end());
        int i = 0, ans = 0, d = 0;
        int n = v.size();
        while (pq.size() > 0 || i < n) {
            if (pq.size() == 0)
                d = v[i][0];
            while (i < n && v[i][0] <= d) {
                pq.push(v[i][1]);
                i++;
            }
            pq.pop();
            ans++;
            d++;
            while (pq.size() > 0 && pq.top() < d)
                pq.pop();
        }
        return ans;
    }
};