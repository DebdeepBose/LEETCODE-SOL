class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        // Dis is BS on indexes
        int low = 0;
        int high = n - 1;

        /*Now this is kinda tricky to understand, imagine an ideal situation
        like [1,2,3] here as u can see we got no missing elements so naturally
        the difference between the number and next-index is 0 throughout but
        suppose we get this [1,2,4,6] as u can see we no longer get a difference
        of 0, cuz some numbers are missing and to solve this we gotta find UPTO
        i index, how many numbers are missing which is easy, look 1-1(next
        index) = 0, 2-2(next index) = 0, 4-3 = 1 (1 number missing), 6-4 = 2 (2
        numbers missing), so our missing array becomes [0,0,1,2], now this is
        the array we shud apply BS on , say our k = 1 all we gotta do is run BS
        and check if k falls somewhere or not*/

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int numberOfMissesUntilNow = arr[mid] - (mid + 1);

            // If misses < k we eliminate left, if >= we eliminate right
            if (numberOfMissesUntilNow < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
        /* Imagine we got an array [1,2,3] and k = 2, there are no missing
         elements in that array aka [0,0,0] our BS will fail terribly XD,
         anyways so we simply pass on +k to get the next k element after the
         last element in the array, also it works even if miss array isnt 0
         throughout*/
    }
};