class Solution {
    public Boolean isodd(int n) {
        return n % 2 == 1;
    }

    public int numberOfSubarrays(int[] v, int k) {
        int n = v.length;
        int l = 0;
        int r = 0;
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
                int tmpl = l;
                while (tmpl < n && !isodd(v[tmpl])) {
                    c++;
                    tmpl++;
                }
                c++;
            }
            r++;
        }
        return c;
    }
}