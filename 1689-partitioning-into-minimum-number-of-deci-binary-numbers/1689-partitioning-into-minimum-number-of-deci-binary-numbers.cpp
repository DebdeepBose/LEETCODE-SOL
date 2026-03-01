class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int maxi = 0;
        for (auto& e : s) {
            maxi = max(maxi, e - '0');
        }
        return maxi;
    }
};