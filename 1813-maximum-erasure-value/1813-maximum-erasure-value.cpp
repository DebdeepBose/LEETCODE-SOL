class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int n = v.size();
        long long maxSum = 0, sum = 0;

        while (r < n) {
            if (mp[v[r]] == 0) {
                mp[v[r]]++;
                sum += v[r];
                maxSum = max(maxSum, sum);
                r++;
            } else {
                while (mp[v[r]] > 0) {
                    mp[v[l]]--;
                    sum -= v[l];
                    if (mp[v[l]] == 0) {
                        mp.erase(v[l]);
                    }
                    l++;
                }
                mp[v[r]]++;
                sum += v[r];
                r++;
            }
        }

        return maxSum;
    }
};
