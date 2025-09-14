class Solution {
    public int[] maxKDistinct(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums); 

        List<Integer> res = new ArrayList<>();
        res.add(nums[n - 1]);
        k--;

        int i = n - 2;
        while (k > 0 && i >= 0) {
            if (nums[i] != nums[i + 1]) {
                res.add(nums[i]);
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
