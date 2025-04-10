class Solution {
public:
    void merge(vector<int>& count, vector<pair<int, int>>& numIndex, int low,
               int mid, int high) {
        vector<pair<int, int>> referencePair;

        int left = low;
        int right = mid + 1;
        int numRightCount = 0;

        while (left <= mid && right <= high) {
            if (numIndex[left].first <= numIndex[right].first) {
                count[numIndex[left].second] += numRightCount;
                referencePair.push_back(numIndex[left]);
                left++;
            } else {
                numRightCount++;
                referencePair.push_back(numIndex[right]);
                right++;
            }
        }

        while (left <= mid) {
            count[numIndex[left].second] += numRightCount;
            referencePair.push_back(numIndex[left]);
            left++;
        }
        while (right <= high) {
            referencePair.push_back(numIndex[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            numIndex[i] = referencePair[i - low];
        }
    }
    void mergeSort(vector<int>& count, vector<pair<int, int>>& numIndex,
                   int low, int high) {

        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(count, numIndex, low, mid);
        mergeSort(count, numIndex, mid + 1, high);
        merge(count, numIndex, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {

        int size = nums.size();

        if (size == 1) {
            return {0};
        }

        vector<pair<int, int>> numIndex(size);
        for (int i = 0; i < size; i++) {
            numIndex[i] = make_pair(nums[i], i);
        }

        vector<int> count(size, 0);

        mergeSort(count, numIndex, 0, size - 1);

        return count;
    }
};