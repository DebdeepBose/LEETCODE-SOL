class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        int n = v.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && v[i] == v[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && v[j] == v[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = 1LL * v[i] + v[j] + v[k] + v[l];
                    if (sum == t) {
                        ans.push_back({v[i], v[j], v[k], v[l]});
                        while (k < l && v[k] == v[k + 1]) {
                            k++;
                        }
                        while (k < l && v[l] == v[l - 1]) {
                            l--;
                        }
                        k++;
                        l--;
                    } else if (sum > t) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }

        return ans;
    }
};
