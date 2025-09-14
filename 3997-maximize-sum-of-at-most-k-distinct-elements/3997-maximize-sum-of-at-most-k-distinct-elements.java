class Solution {
    public int[] maxKDistinct(int[] v, int k) {
        int n = v.length;
        Arrays.sort(v); 

        List<Integer> res = new ArrayList<>();
        res.add(v[n - 1]);
        k--;

        int i = n - 2;
        while (k > 0 && i >= 0) {
            if (v[i] != v[i + 1]) {
                res.add(v[i]);
                k--;
            }
            i--;
        }

        int[] ans = new int[res.size()];
        for (int j = 0; j < res.size(); j++) {
            ans[j] = res.get(j);
        }

        return ans;
    }
}
