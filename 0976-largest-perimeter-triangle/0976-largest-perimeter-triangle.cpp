class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();

        for (int i = n - 1; i >= 2; i--) {
            if (v[i - 2] + v[i - 1] > v[i]) {
                return v[i - 2] + v[i - 1] + v[i];
            }
        }
        return 0; 
    }
};
