class Solution {
public:
    int minMoves(vector<int>& v) {
        int mini = *min_element(v.begin(),v.end());
        int ans = 0;
        for (int e : v) {
            ans += e - mini;
        }
        return ans;
    }
};