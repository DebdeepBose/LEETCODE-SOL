class Solution {
public:
    int minAddToMakeValid(string s) {
        int stack_size = 0;
        int unmatch = 0;
        for (char c : s) {
            if (c == '(') {
                stack_size++; // stack push 
            }
            else if (c == ')' && stack_size > 0) {
                stack_size--; // stack pop
            } else {
                unmatch++;
            }
        }
        return stack_size + unmatch;
    }
};
