class Solution {
public:
    bool isodd(int n) { return n % 2 == 1; }
    
    int numberOfSubarrays(vector<int>& v, int k) {
        int l = 0;
        int r = 0;
        int n = v.size();
        int c = 0;
        int o = 0;
        
        while (r < n) {
            if (isodd(v[r])) {
                o++;
            }
            while (o > k) {
                if (isodd(v[l])) {
                    o--;
                }
                l++;
            }
            if (o == k) {
                int tempL = l;
                while (tempL < n && !isodd(v[tempL])) {
                    c++;
                    tempL++;
                }
                c++;
            }
            r++;
        }
        
        return c;
    }
};
