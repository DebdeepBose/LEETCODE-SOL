class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& v, vector<int>& l,
                                          vector<int>& r) {
        int n = v.size();
        vector<bool> ans(l.size(), true);

        for (int i = 0; i < l.size(); i++) {
            vector<int> tmp;
            for (int j = l[i]; j <= r[i]; j++) {
                tmp.push_back(v[j]);
            }
            sort(tmp.begin(), tmp.end());
            for (int k = 1; k < tmp.size() - 1; k++) {
                if (tmp[k] - tmp[k - 1] != tmp[k + 1] - tmp[k]) {
                    ans[i] = false;
                }
            }
        }
        return ans;
    }
};