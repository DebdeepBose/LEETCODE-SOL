class Solution {
public:
    int longestConsecutive(vector<int>& v) {

        if(v.empty()){
            return 0;
        }

        sort(v.begin(), v.end());
        int maxc = 1, c = 1;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                continue;
            }
            if (v[i] == v[i - 1] + 1) {
                c++;
            } else {
                maxc = max(maxc, c);
                c = 1; 
            }
        }

        return max(maxc, c);
    }
};
