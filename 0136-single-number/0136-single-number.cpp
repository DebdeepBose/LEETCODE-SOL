class Solution {
public:
    int singleNumber(vector<int>& v) {
        
        int n = v.size();
        int x = 0;

        for(int i=0;i<n;i++){
            x ^= v[i];
        }
    return x;
    }
};