class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        int n = v.size();
        int left = 0;
        while (left + 1 < n && v[left] <= v[left + 1]) {
            left++;
        }
        if (left == n - 1) {
            return 0;
        }
        int right = n - 1;
        while (right > left && v[right] >= v[right - 1]) {
            right--;
        }
        int minLength = min(n - left - 1, right);
        int i = 0;
        int j = right;
        while (i <= left && j < n) {
            if (v[i] <= v[j]) {
                minLength = min(minLength, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return minLength;
    }
};
