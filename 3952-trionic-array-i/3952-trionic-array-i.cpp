class Solution {
public:
    bool isTrionic(vector<int>& v) {
        int n = v.size();
        if (n < 3){
            return false;
        }
        int i = 0;
        int c = 0;
        while (i + 1 < n && v[i + 1] > v[i]) {
            i++;
            if (c == 0) {
                c++;
            }
            if (i == n - 1) {
                return false;
            }
        }
        while (i + 1 < n && v[i + 1] < v[i]) {
            i++;
            if (c == 1) {
                c++;
            }
            if (i == n - 1) {
                return false;
            }
        }
        while (i + 1 < n && v[i + 1] > v[i]) {
            i++;
            if (c == 2) {
                c++;
            }
            if (i == n - 1 && c == 3) {
                return true;
            }
        }
        return false;
    }
};
