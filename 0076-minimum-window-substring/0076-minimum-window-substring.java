class Solution {
    public String minWindow(String s, String t) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char c : t.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        int l = 0, r = 0, n = s.length();
        int mini = Integer.MAX_VALUE;
        int count = 0;
        int startIdx = -1;

        while (r < n) {
            if (mp.containsKey(s.charAt(r))) {
                if (mp.get(s.charAt(r)) > 0) {
                    count++;
                }
                mp.put(s.charAt(r), mp.get(s.charAt(r)) - 1);
            }

            while (count == t.length()) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    startIdx = l;
                }
                if (mp.containsKey(s.charAt(l))) {
                    mp.put(s.charAt(l), mp.get(s.charAt(l)) + 1);
                    if (mp.get(s.charAt(l)) > 0) {
                        count--;
                    }
                }
                l++;
            }
            r++;
        }

        return startIdx == -1 ? "" : s.substring(startIdx, startIdx + mini);
    }
}
