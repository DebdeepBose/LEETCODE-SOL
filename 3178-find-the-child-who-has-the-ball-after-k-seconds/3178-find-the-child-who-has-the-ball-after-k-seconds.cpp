class Solution {
public:
    int numberOfChild(int n, int k) {
        int el = k/(n-1);
        int m = k%(n-1);
        return el%2?(n-1)-m:m;
    }
};