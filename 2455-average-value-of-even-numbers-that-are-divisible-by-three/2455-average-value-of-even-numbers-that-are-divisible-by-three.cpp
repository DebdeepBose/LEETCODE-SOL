class Solution {
public:
    int averageValue(vector<int>& v) {
        int s = 0, c = 0;
        for (auto& e : v) {
            if (e % 2 == 0 && e % 3 == 0) {
                s += e;
                c++;
            }
        }
        return c > 0 ? s / c : 0;
    }
};