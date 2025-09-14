class Solution {
public:
    int minSetSize(vector<int>& v) {

        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        int n = v.size();
        int half = n / 2;
        for (auto e : v) {
            mp[e]++;
        }
        for (auto e : mp) {
            pq.push({e.second, e.first});
        }

        int ss = 0;

        while (!pq.empty()) {
            auto [f, num] = pq.top();
            pq.pop();
            n -= f;
            ss++;
            if (n <= half) {
                return ss;
            }
        }
        return ss;
    }
};