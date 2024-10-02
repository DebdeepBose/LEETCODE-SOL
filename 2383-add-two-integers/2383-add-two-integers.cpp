class Solution {
public:
    int sum(int a, int b) {
        int andsum = a & b;
        int orsum = a | b;
        return andsum + orsum;
    }
};