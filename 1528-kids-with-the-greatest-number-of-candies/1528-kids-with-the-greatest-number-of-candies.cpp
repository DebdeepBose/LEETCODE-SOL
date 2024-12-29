class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int n) {
        int maxv = *max_element(v.begin(), v.end());
        int l = maxv - n;
        vector<bool> ans;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= l) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};