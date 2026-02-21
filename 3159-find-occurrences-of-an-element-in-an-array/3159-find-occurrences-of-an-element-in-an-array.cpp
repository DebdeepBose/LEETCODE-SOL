class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& v, vector<int>& q, int x) {
        vector<int> positions;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == x) {
                positions.push_back(i);
            }
        }

        vector<int> ans;
        for (int k : q) {
            if (k <= positions.size()) {
                ans.push_back(positions[k - 1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};