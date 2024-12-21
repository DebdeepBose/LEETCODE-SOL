class Solution {
public:
    int maxProductDifference(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int a = v[n - 1];
        int b = v[n - 2];
        int c = v[0];
        int d = v[1];
        return (a * b) - (c * d);
    }
};