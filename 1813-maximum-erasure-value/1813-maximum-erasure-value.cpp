class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        unordered_set<int> s;
        int l = 0;
        int n = v.size();
        long long maxSum = 0, sum = 0;

        for (int r = 0; r < n; r++) {
            while (s.count(v[r])>0) {
                s.erase(v[l]);
                sum -= v[l];
                l++;
            }
            s.insert(v[r]);
            sum += v[r];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
