class Solution {
public:
    typedef pair<int, pair<int, int>> pii;

    int euclidDist(int a, int b) {
        int asq = a * a;
        int bsq = b * b;
        return asq + bsq;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto e : v) {
            int f = e[0], s = e[1];
            int d = euclidDist(f, s);
            pq.push({d, {f, s}});
        }

        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x, y});
            pq.pop();
        }

        return ans;
    }
};
