class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        int n = v.size();
        int l = 0;
        int r = k - 1;
        vector<int> ans;
        while (r < n) {
            bool flag = true;
            for (int i = l; i <= r - 1; i++) {
                if (v[i] >= v[i + 1] || v[i + 1] - v[i] > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                ans.push_back(-1);
            } else {
                int maxi = INT_MIN;
                for (int i = l; i <= r; i++) {
                    maxi = max(maxi, v[i]);
                }
                ans.push_back(maxi);
            }
            l++;
            r++;
        }
        return ans;
    }
};