class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        if (ed[0][0] == ed[1][0] || ed[0][0] == ed[1][1]) {
            return ed[0][0];
        }
        
        return ed[0][1];
    }
};