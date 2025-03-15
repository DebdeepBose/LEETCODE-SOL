class Solution {
public:
    int minCapability(vector<int>& v, int k) {
        int left = 1, right = 1e9, n = v.size();
        while (left < right) {
            int mid = (left + right) / 2, take = 0;
            for (int i = 0; i < n; i++)
                if (v[i] <= mid) {
                    take += 1;
                    i++;
                }
            if (take >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left; 
    }
};