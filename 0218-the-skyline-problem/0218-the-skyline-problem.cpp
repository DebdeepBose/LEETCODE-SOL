class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bld) {
        vector<vector<int>> res;
        multiset<int> ms{0};
        vector<pair<int, int>> pts;

        for (auto b : bld) {
            pts.emplace_back(b[0], -b[2]);
            pts.emplace_back(b[1], b[2]);
        }

        sort(pts.begin(), pts.end());

        int h = 0;

        for (auto p : pts) {
            int x = p.first, ht = p.second;

            if (ht < 0) ms.insert(-ht);
            else ms.erase(ms.find(ht));

            int top = *ms.rbegin();
            if (h != top) {
                h = top;
                res.push_back({x, h});
            }
        }

        return res;
    }
};
