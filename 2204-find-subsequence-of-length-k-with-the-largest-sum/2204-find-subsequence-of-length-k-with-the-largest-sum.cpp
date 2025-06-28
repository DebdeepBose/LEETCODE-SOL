class Solution {
public:
    typedef pair<int, int> p;
    vector<int> maxSubsequence(vector<int>& v, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;

        for (int i = 0; i < v.size(); i++) {
            pq.push({v[i], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        priority_queue<p, vector<p>, greater<p>> pq2;

        while (!pq.empty()) {
            int f = pq.top().second;
            int s = pq.top().first;
            pq2.push({f, s});
            pq.pop();
        }

        vector<int> ans;

        while (!pq2.empty()) {
            ans.push_back(pq2.top().second);
            pq2.pop();
        }

        return ans;
    }
};