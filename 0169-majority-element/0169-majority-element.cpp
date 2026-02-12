class Solution {
public:
    int majorityElement(vector<int>& v) {
        int c = 0;
        int cand = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (c == 0) {
                cand = v[i];
            }
            if (v[i] == cand) {
                c++;
            } else {
                c--;
            }
        }
        return cand;
    }
};