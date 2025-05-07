class Solution {
public:
    int minimumDifference(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int l = 0;
        int r = k - 1;
        int n = v.size();
        int mindif = INT_MAX;
        while (r < n) {
            int dif = v[r] - v[l];
            mindif = min(mindif, dif);
            r++;
            l++;
        }
        return mindif;
    }
};