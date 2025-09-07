class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int st = 1;
        if (n % 2 == 0) {
            while (n != 0) {
                ans.push_back(st);
                ans.push_back(-st);
                n -= 2;
                st++;
            }
        } else {
            ans.push_back(0);
            n--;
            while (n != 0) {
                ans.push_back(st);
                ans.push_back(-st);
                n -= 2;
                st++;
            }
        }
        return ans;
    }
};