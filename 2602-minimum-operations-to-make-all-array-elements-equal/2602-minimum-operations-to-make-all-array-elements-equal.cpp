class Solution {
public:
    vector<long long> minOperations(vector<int>& v, vector<int>& q) {
        sort(v.begin(), v.end());
        int n = v.size();

        vector<long long> pref(n);
        pref[0] = v[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + v[i];

        vector<long long> ans;

        for (int x : q) {
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();

            long long leftSum  = (idx > 0 ? pref[idx - 1] : 0);
            long long rightSum = pref[n - 1] - leftSum;

            long long leftCost  = 1LL * x * idx - leftSum;
            long long rightCost = rightSum - 1LL * x * (n - idx);

            ans.push_back(leftCost + rightCost);
        }

        return ans;
    }
};