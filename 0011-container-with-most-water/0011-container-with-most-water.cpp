class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        if (n == 2) {
            return min(v[0], v[1]);
        }
        int i = 0;
        int j = n - 1;
        int vol, maxvol = INT_MIN;
        while (i < j) {
            vol = (j - i) * min(v[i], v[j]);
            maxvol = max(maxvol, vol);
            if (v[i] < v[j]) {
                i++;
            } else if (v[j] < v[i]) {
                j--;
            } else {
                i++;
                j--;
            }
        }
        return maxvol;
    }
};