class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size(), c = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                if (sum == k) {
                    c++;
                }
            }
        }
        return c;
    }
};