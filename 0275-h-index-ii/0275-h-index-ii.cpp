class Solution {
public:
    int hIndex(vector<int>& citations) {
        /*This question's description is one of the worst description mankind
         * has ever witnessed*/

        int n = citations.size();
        int low = 0;
        int high = n - 1;

        // Yeah im taking a variable to store hIndex, deal with it
        int hIndex = -1;

        /* Now the main idea, aka what this question wants, is that we find a
           valid hIndex and citations[hIndex] should have >= number of papers
           from that index to the end. I know it already sounds terrible.
           To dumb it down, basically if the array has an element 4, we need
           to check: are there 4 elements >= 4? If yes, that's a valid hIndex.
           If no, then the number is too big, gotta reduce it. */

        /* It doesn't end here — even if we find a valid index, we gotta keep
           searching for maximum hIndex, so we move left in that case, aka high
           = mid - 1. Now you might say: wait, if we move left, isn't that a
           smaller number on the left? Weren't we searching for max hIndex?
           Yeah, but the question asks us to return the total number of papers
           from that index to the end not the array
           index itself. So the smaller our index, the bigger the h-index. Got
           it? */

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int citationsUntilEnd = n - mid;
            if (citations[mid] >= citationsUntilEnd) {
                hIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return hIndex != -1 ? n - hIndex : 0;
    }
};