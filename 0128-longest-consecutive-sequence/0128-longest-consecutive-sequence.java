class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int longestConsecutiveSequence = 0;
        for (int num : nums) {
            if (!set.contains(num - 1)) {
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while (set.contains(currentNumber + 1)) {
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = Math.max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
}