class Solution {
public:
    void allsub(vector<vector<int>>& ans, vector<int>& tmp, int n, int st, vector<int>& v) {
        if(st >= n) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(v[st]);
        allsub(ans, tmp, n, st + 1, v);
        tmp.pop_back();
        allsub(ans, tmp, n, st + 1, v);
    }

    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        allsub(ans, tmp, n, 0, v);
        return ans;
    }
};
