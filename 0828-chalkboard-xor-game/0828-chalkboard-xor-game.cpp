class Solution {
public:
    bool xorGame(vector<int>& v) {
        int xorVal = 0;
        for (auto e : v) {
            xorVal ^= e;
        }
        return xorVal == 0 || v.size() % 2 == 0;
    }
};