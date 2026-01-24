class Solution {
public:
    int minPairSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        for (int i = 0; i < n / 2; i++) {
            pq.push(v[i] + v[n - i - 1]);
        }
        return pq.top();
    }
};