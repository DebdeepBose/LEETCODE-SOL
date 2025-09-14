class Solution {
public:
    vector<int> maxKDistinct(vector<int>& v, int k) {
        int n = v.size();
        sort(v.rbegin(), v.rend());

        vector<int> ans;
        ans.push_back(v[0]);
        k--;

        int i = 1;
        while (k > 0 && i < n) {
            if (v[i] != v[i - 1]) {
                ans.push_back(v[i]);
                k--;
            }
            i++;
        }

        return ans;
    }
};

