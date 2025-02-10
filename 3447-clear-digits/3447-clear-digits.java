class Solution {
    public String clearDigits(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                st.push(c);
            } else if (Character.isDigit(c)) {
                if (Character.isLetter(st.peek())) {
                    st.pop();
                }
            }
        }
        StringBuilder r = new StringBuilder();
        while (!st.isEmpty()) {
            r.append(st.pop());
        }
        return r.reverse().toString();
    }
}