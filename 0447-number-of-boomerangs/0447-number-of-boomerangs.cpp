class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int pointLen = points.size();

        if (pointLen <= 2) {
            return 0;
        }

        int boomerangs = 0;

        for (int i = 0; i < pointLen; i++) {

            unordered_map<double, int> mp;

            for (int j = 0; j < pointLen; j++) {

                if (i == j) {
                    continue;
                }

                int distX = points[j][0] - points[i][0];
                int distY = points[j][1] - points[i][1];

                long long sqX = distX * distX;
                long long sqY = distY * distY;

                long long sqSum = sqX + sqY;

                double dist = sqrt(sqSum);

                mp[dist]++;
            }

            for (auto e : mp) {
                    boomerangs += (e.second * (e.second - 1));
            }
        }

        return boomerangs;
    }
};