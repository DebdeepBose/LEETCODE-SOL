class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();

        if (n == 1) {
            return v[0];
        }

        int maj;
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (c == 0) {
                maj = v[i];
            }
            if (v[i] == maj) {
                c++;
            } else {
                c--;
            }
        }
        return maj;
    }
};