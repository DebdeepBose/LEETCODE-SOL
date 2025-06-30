class Solution {
public:
    vector<string> topKFrequent(vector<string>& v, int k) {
        unordered_map<string, int> mp;
        for (auto e : v) {
            mp[e]++;
        }

        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto e : mp) {
            pq.push({e.second, e.first});
        }

        vector<string> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
