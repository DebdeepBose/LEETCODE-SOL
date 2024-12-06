class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxi) {
        set<int> st (b.begin(), b.end());  
        int s = 0;
        int c = 0;
    
        for (int i = 1; i <= n; i++) {
            if (st.count(i) == 0) {  
                if (s + i <= maxi) {
                    s += i;
                    c++;
                } else {
                    return c;
                }
            }
        }
        return c;
    }
};
