class Solution {
public:
    long long maximumMedianSum(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
    
        int f = n / 3;
        long long median = 0;
        for (int i = f; i < n; i += 2) {
            median += v[i];
        }
        return median;
    }
};