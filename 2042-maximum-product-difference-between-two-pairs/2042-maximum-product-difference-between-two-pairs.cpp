class Solution {
public:
    int maxProductDifference(vector<int>& v) {
        int n = v.size();
        int maxi = INT_MIN;
        int smaxi = INT_MIN;
        int mini = INT_MAX;
        int smini = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (v[i] > maxi) {
                smaxi = maxi;
                maxi = v[i];
            } else if (v[i] > smaxi) {
                smaxi = v[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[i] < mini) {
                smini = mini;
                mini = v[i];
            } else if (v[i] < smini) {
                smini = v[i];
            }
        }

        long long maxProd = (long long)maxi * smaxi;
        long long minProd = (long long)mini * smini;

        return (int)(maxProd - minProd);
    }
};
