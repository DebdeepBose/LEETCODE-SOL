class Solution {
public:
    int thirdMax(vector<int>& v) {
        if (v.size() == 1) {
            return v[0];
        }
        if (v.size() == 2) {
            return max(v[0], v[1]);
        }
        
        int fmax = *max_element(v.begin(), v.end());
        int smax = INT_MIN;
        int tmax = INT_MIN;
        int c1 = 0;

        for (int i = 0; i < v.size(); i++) {
            if (smax < v[i] && v[i] != fmax) {
                smax = v[i];
                c1++;
            }
        }
        
        if (c1 == 0) {
            return fmax; 
        }

        int c2 = 0;

        for (int i = 0; i < v.size(); i++) {
            if ((tmax < v[i] || v[i] == INT_MIN) && (v[i] != fmax && v[i] != smax)) {
                tmax = v[i];
                c2++;
            }
        }
        
        if (c2 > 0) {
            return tmax;
        } else {
            return fmax;
        }
    }
};
