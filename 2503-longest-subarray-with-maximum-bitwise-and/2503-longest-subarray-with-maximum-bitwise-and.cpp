class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int largest = *max_element(v.begin(),v.end());
        int s = 0;
        int maxs = 0;
        for (auto e : v) {
            if (e == largest) {
                s++;
                maxs = max(maxs, s);
            } else {
                s = 0;
            }
        }
        return maxs;
    }
};