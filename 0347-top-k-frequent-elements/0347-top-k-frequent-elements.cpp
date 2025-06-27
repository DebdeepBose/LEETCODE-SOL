class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        unordered_map<int, int> mp;

        for (auto e : v) {
            mp[e]++;
        }

        for (auto e : mp) {
            pq.push({e.second, e.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};