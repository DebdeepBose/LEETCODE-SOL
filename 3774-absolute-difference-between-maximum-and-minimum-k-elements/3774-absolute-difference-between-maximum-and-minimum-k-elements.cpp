class Solution {
public:
    int absDifference(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();
        int lsum = 0;
        int ssum = 0;
        int i = 0;
        while (k--) {
            ssum += v[i];
            lsum += v[n - i - 1];
            i++;
        }
        return abs(lsum - ssum);
    }
};