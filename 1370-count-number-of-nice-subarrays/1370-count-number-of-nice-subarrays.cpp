class Solution {
public:
    bool isodd(int n) { return n % 2 == 1; }
    int numberOfSubarrays(vector<int>& v, int goal) {
        int left = 0, right = 0, count = 0, oddcnt = 0;
        int n = v.size();
        while (right < n) {

            if (isodd(v[right])) {
                oddcnt++;
            }

            while (oddcnt > goal) {
                if (isodd(v[left])) {
                    oddcnt--;
                }
                left++;
            }

            if (oddcnt == goal) {
                int tmpl = left;
                while (tmpl < n && !isodd(v[tmpl])) {
                    count++;
                    tmpl++;
                }
                count++;
            }
            right++;
        }
        return count;
    }
};