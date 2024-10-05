class Solution {
    private void swap(int[] v, int a, int b) {
        v[a] = v[a] ^ v[b];
        v[b] = v[a] ^ v[b];
        v[a] = v[a] ^ v[b];
    }

    public int firstMissingPositive(int[] v) {
        int n = v.length;
        for (int i = 0; i < n; i++) {
            while (v[i] > 0 && v[i] <= n && v[v[i] - 1] != v[i]) {
                swap(v, i, v[i] - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (v[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}