class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int lst = ls[i];
            int d = ld[i];
            for (int j = 0; j < m; j++) {
                int wst = ws[j];
                int dd = wd[j];

                int le = lst + d;
                int sw = max(le, wst);
                int f1 = sw + dd;

              
                int we = wst + dd;
                int sl = max(we, lst);
                int f2 = sl + d; 

                ans = min({ans, f1, f2});
            }
        }

        return ans;
    }
};
