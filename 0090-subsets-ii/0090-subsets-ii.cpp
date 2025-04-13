class Solution {
public:
    void gen(vector<int>& v, set<vector<int>>& ans, vector<int>& tmp, int n,
             int i) {
        if (i >= n) {
            ans.insert(tmp);
            return;
        }
        gen(v, ans, tmp, n, i + 1);
        tmp.push_back(v[i]);
        gen(v, ans, tmp, n, i + 1);
        tmp.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> tmp;
        set<vector<int>> ans;
        
        gen(v, ans, tmp, n, 0);
        vector<vector<int>> finalres(ans.begin(),ans.end());
        return finalres;
    }
};