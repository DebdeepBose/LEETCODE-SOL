class Solution {
public:
    int heightChecker(vector<int>& v) {
        vector<int> u(v.begin(), v.end());
        sort(u.begin(), u.end());
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            if (u[i] != v[i]) {
                c++;
            }
        }
        return c;
    }
};