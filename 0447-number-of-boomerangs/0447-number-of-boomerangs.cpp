class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int pointLen = points.size();

        // Cant form boomerangs if there are less than 3 points
        if (pointLen <= 2) {
            return 0;
        }

        int boomerangs = 0;

        /* Take a notebook and draw a few points on a makeshift graph paper
        you would notice that we can only form boomerangs with points that are
        equidistant, now all u gotta do is, consider each coordinate the center
        and measure the distances from it to all other points. If there are x
        number of equidistant points then the total boomerangs formed would be 
        x * (x - 1) */

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