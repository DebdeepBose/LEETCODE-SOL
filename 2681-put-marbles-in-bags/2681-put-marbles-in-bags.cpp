class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        vector<int> ans;
        for (int i = 0; i < v.size() - 1; ++i) {
            ans.push_back(v[i] + v[i + 1]);
        }

        // Sorting the ans array
        sort(ans.begin(), ans.end());

        int n = ans.size();
        long long sumMax = accumulate(ans.end() - (k - 1), ans.end(), 0LL);
        long long sumMin = accumulate(ans.begin(), ans.begin() + (k - 1), 0LL);

        return sumMax - sumMin;
    }
};