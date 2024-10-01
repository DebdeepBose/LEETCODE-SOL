class Solution {
    public String convert(String s, int n) {
       
        int si = s.length();

         if (n == 1 || n >= si) {
            return s;
        }

        int j = 0;
        int dir = -1;

        String[] v = new String[n];
        for (int i = 0; i < n; i++) {
            v[i] = "";
        }

        for (int i = 0; i < si; i++) {
            if (j == 0 || j == n - 1) {
                dir *= -1;
            }
            v[j] += s.charAt(i);
            if (dir == 1) {
                j++;
            } else {
                j--;
            }
        }

        StringBuilder ans = new StringBuilder();
        for (String e : v) {
            ans.append(e);
        }
        return ans.toString();
    }
}
