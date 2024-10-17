class Solution {
public:
    bool isGoodArray(vector<int>& v) {
        int hcf = v[0];
        for (auto e : v) {
            hcf = __gcd(hcf, e);
        }
        return hcf == 1;
    }
};