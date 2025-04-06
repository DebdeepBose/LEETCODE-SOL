class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();

        for (int i = 0; i < n - 2; i++) {
            if (v[i] > 0) break; // No point in checking further

            if (i > 0 && v[i] == v[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int s = v[i] + v[j] + v[k];
                if (s == 0) {
                    ans.push_back({v[i], v[j], v[k]});
                    while (j < k && v[j] == v[j + 1]) j++;
                    while (j < k && v[k] == v[k - 1]) k--;
                    j++;
                    k--;
                } else if (s < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};
