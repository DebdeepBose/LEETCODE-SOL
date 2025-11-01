class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& v, int k) {

        // pair<quotient,pair<num,denom>>
        priority_queue<pair<double, pair<int, int>>> pq;

        int n = v.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pq.push({(double)v[i] / (double)v[j], {v[i], v[j]}});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};