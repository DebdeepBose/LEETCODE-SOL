class Solution {
public:
    int numRescueBoats(vector<int>& v, int lim) {
        sort(v.begin(), v.end());
        int n = v.size();
        int i = 0;
        int j = n - 1;
        int boat = 0; 
        while (i <= j) {
            if (v[i] + v[j] <= lim) {
                i++;
            }
            j--;

            boat++;
        }
        return boat;
    }
};