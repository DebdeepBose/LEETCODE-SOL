class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(), v.end());
        int toSub = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > 0) {
                if (v[i] - toSub > 0) {
                    v[i] -= toSub;
                } else {
                    v[i] = 0;
                }
            }
            toSub++;
        }
        long long hap = 0LL;
        int i = 0;
        while (k--) {
            hap += v[n - i - 1];
            i++;
        }

        return hap;
    }
};