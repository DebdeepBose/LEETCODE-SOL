class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& v) {
        vector<set<int>> rows(n + 1), cols(n + 1);
        for (auto i : v) {
            int x = i[0], y = i[1];
            rows[x].insert(y);
            cols[y].insert(x);
        }

        int c = 0;
        for (auto i : v) {
            int x = i[0], y = i[1];

            auto it = rows[x].lower_bound(y);
            bool hasLeft = (it != rows[x].begin());
            bool hasRight = (it != rows[x].end() && next(it) != rows[x].end());

            auto it2 = cols[y].lower_bound(x);
            bool hasAbove = (it2 != cols[y].begin());
            bool hasBelow =
                (it2 != cols[y].end() && next(it2) != cols[y].end());

            if (hasLeft && hasRight && hasAbove && hasBelow) {
                c++;
            }
        }
        return c;
    }
};