class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l = 0;
        int n = v.size();
        int r = n - 1;
        int c = 0;
        while (l < r) {
            if (v[l] + v[r] == k) {
                c++;
                l++;
                r--;
            } else if (v[l] + v[r] > k) {
                r--;
            } else if (v[l] + v[r] < k) {
                l++;
            }
        }
        return c;
    }
};