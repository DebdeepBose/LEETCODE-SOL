class Solution {
public:
    int maxArea(vector<int>& v) {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
        int n = v.size();
        if (n == 2) {
            return min(v[0], v[1]);
        }
        if (n == 3) {
            int f = min(v[0], v[1]);
            int s = min(v[1], v[2]);
            int t = 2 * min(v[0], v[2]);
            return max({f, s, t});
        }
        int i = 0;
        int j = n - 1;
        int vol, maxvol = 0;
        while (i < j) {
            vol = (j - i) * min(v[i], v[j]);
            maxvol = max(maxvol, vol);
            if (v[i] < v[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxvol;
    }
};