class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int can1, can2;
        int c1 = 0, c2 = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (c1 == 0 && v[i] != can2) {
                c1 = 1;
                can1 = v[i];
            } else if (c2 == 0 && v[i] != can1) {
                c2 = 1;
                can2 = v[i];
            } else if (v[i] == can1) {
                c1++;
            } else if (v[i] == can2) {
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == can1) {
                c1++;
            }
            if (v[i] == can2) {
                c2++;
            }
        }
        vector<int> ans;
        if (c1 > floor(n / 3)) {
            ans.push_back(can1);
        }
        if (c2 > floor(n / 3) && can1 != can2) {
            ans.push_back(can2);
        }
        return ans;
    }
};