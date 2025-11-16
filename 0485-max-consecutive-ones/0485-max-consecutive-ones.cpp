class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int n = v.size();
        int maxC = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                c++;
            } else {
                maxC = max(maxC, c);
                c = 0;
            }
        }
        return max(maxC, c);
    }
};