class Solution {
public:
    double checkpiles(int mid, vector<int>& piles, int n) {
        double totalHoursTaken = 0;
        for (int i = 0; i < n; i++) {
            totalHoursTaken += ceil((double)piles[i] / (double)mid);
        }
        return totalHoursTaken;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mintime = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            double hoursTaken = checkpiles(mid, piles, n);
            if (hoursTaken <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};