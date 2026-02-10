class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();

        if (n < 3) {
            return {};
        }

        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < n - 2) {
            if (v[i] > 0) {
                break;
            }
            while (i > 0 && i < n - 2 && v[i] == v[i - 1]) {
                i++;
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = v[i] + v[j] + v[k];
                if (sum == 0) {
                    ans.push_back({v[i], v[j], v[k]});
                    while (j < k && v[j] == v[j + 1]) {
                        j++;
                    }
                    while (j < k && v[k] == v[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};