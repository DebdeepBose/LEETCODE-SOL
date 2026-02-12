class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int c = 0;
        int can = 0;
        for (int i = 0; i < n; i++) {
            if (c == 0) {
                can = v[i];
            }
            if (v[i] == can) {
                c++;
            } else {
                c--;
            }
        }
        return can;
    }
};