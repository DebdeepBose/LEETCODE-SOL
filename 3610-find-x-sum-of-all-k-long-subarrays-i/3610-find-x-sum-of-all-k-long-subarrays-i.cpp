class Solution {
public:
    vector<int> findXSum(vector<int>& v, int k, int x) {
        int l = 0;
        int n = v.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for (int r = 0; r < n; r++) {
            mp[v[r]]++;
            while (r - l + 1 > k) {
                mp[v[l]]--;
                if (mp[v[l]] == 0) {
                    mp.erase(v[l]);
                }
                l++;
            }
            if (r - l + 1 == k) {
                priority_queue<pair<int, int>> pq;
                for (auto e : mp) {
                    pq.push({e.second, e.first});
                }
                int csum = 0;
                for (int i = 0; i < x && !pq.empty(); i++) {
                    auto t = pq.top();
                    pq.pop();
                    csum += t.second * t.first;
                }
                res.push_back(csum);
            }
        }
        return res;
    }
};
