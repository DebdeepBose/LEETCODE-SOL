class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        int n = v.size();
        vector<int> hash(n, 0);
        for (int i = 0; i < n; i++) {
            hash[v[i] - 1]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (hash[i] == 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};