class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;

        for (int e : v) {
            mp[e]++;
        }

        for (auto e : mp) {
            pq.push({e.second, e.first});
        }

        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
