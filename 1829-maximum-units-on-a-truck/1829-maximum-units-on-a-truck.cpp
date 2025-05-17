class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int t) {
        int n = v.size();
        vector<pair<double, int>> ratioIdx;
        double ans = 0.0;

        for (int i = 0; i < n; i++) {
            if (v[i][0] == 0) continue;
            double ratio = (double)v[i][1];
            ratioIdx.push_back({ratio, i});
        }

        sort(ratioIdx.rbegin(), ratioIdx.rend());
        for (int i = 0; i < ratioIdx.size(); i++) {
            int idx = ratioIdx[i].second;
            int boxes = v[idx][0];
            int unitsPerBox = v[idx][1];

            if (boxes <= t) {
                ans += boxes * unitsPerBox;
                t -= boxes;
            } else {
                ans += t * unitsPerBox;
                break;
            }
        }

        return (int)ans;
    }
};
