class Solution {
public:
    void findComb(vector<int>& v, int i, int t, vector<int>& tmp,
                  set<vector<int>>& st, int sum) {
        if (i == v.size()) {
            if (sum == t) {
                st.insert(tmp);
            }
            return;
        }
        tmp.push_back(v[i]);
        findComb(v, i + 1, t, tmp, st, sum + v[i]);
        tmp.pop_back();
        findComb(v, i + 1, t, tmp, st, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        vector<int> tmp;
        set<vector<int>> st;
        sort(v.begin(),v.end());
        findComb(v, 0, t, tmp, st, 0);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};