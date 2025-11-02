class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {

        vector<string> ans;
        int n = v.size();

        int i = 0;
        for (int j = 0; j < n; j++) {
            if (j == n - 1 || v[j] + 1 != v[j + 1]) {
                string tmp = to_string(v[i]);
                if(v[i]!=v[j]){
                    tmp += "->";
                    tmp += to_string(v[j]);
                }
                ans.push_back(tmp);
                i = j + 1;
            }
        }

        return ans;
    }
};