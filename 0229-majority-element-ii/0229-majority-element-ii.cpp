class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {

        int n = v.size();
        int ca1, ca2;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (c1 == 0 && v[i] != ca2) {
                ca1 = v[i];
                c1++;
            } else if (c2 == 0 && v[i] != ca1) {
                ca2 = v[i];
                c2++;
            } else if (v[i] == ca1) {
                c1++;
            } else if (v[i] == ca2) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == ca1) {
                c1++;
            } else if (v[i] == ca2 && ca1 != ca2) {
                c2++;
            }
        }

        vector<int> ans;
        if (c1 > floor(n / 3)) {
            ans.push_back(ca1);
        }
        if (c2 > floor(n / 3)) {
            ans.push_back(ca2);
        }

        return ans;
    }
};