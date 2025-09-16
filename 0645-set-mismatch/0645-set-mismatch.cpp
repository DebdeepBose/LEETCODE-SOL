class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n = v.size();

        int sum = n * (n + 1) / 2;
        int vsum = accumulate(v.begin(), v.end(), 0);
        sort(v.begin(), v.end());
        int dup = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == v[i + 1]) {
                dup = v[i];
            }
        }

        return {dup, (sum - (vsum - dup))};
    }
};