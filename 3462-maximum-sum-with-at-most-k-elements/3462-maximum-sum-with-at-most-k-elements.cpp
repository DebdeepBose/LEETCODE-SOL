class Solution {
public:
    long long maxSum(vector<vector<int>>& v, vector<int>& u, int k) {
        
        vector<int> el;
        int m = v.size();
        for (int i = 0; i < m; i++) {
            sort(v[i].rbegin(), v[i].rend());

            for (int j = 0; j < u[i]; j++) {
                el.push_back(v[i][j]);
            }
        }

        sort(el.rbegin(), el.rend());

        long long sum = 0;
        int i = 0;
        while (k--) {
            sum += el[i++];
        }

        return sum;
    }
};