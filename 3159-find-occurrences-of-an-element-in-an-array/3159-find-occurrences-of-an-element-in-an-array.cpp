class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& v, vector<int>& q, int x) {
        int oc = 0;
        int maxi = *max_element(q.begin(), q.end());
        int n = v.size();
        int len = max(maxi, n);
        vector<int> ocv(len, -1);

        for (int i = 0; i < n; i++) {
            if (v[i] == x) {
                oc++;
                ocv[oc - 1] = i;
            }
        }
        vector<int> ans(q.size(), -1);
        for (int i = 0; i < q.size(); i++) {
            ans[i] = ocv[q[i] - 1];
        }
        return ans;
    }
};