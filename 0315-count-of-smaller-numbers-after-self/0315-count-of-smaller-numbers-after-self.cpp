class Solution {
public:
    void merge(vector<int>& count, vector<pair<int, int>>& v, int low, int mid, int high){
    vector<pair<int, int>> tmp;
    int left = low;
    int right = mid + 1;
    int numRightSmaller = 0;  // how many right elements are smaller than left

    while (left <= mid && right <= high) {
        if (v[left].first > v[right].first) {
            // v[right] is smaller than v[left]
            // So v[left] gets +1 to its count for each right element being added
            numRightSmaller++;
            tmp.push_back(v[right++]);
        } else {
            // Elements in right half before 'right' are smaller than v[left]
            count[v[left].second] += numRightSmaller;
            tmp.push_back(v[left++]);
        }
    }

    // Remaining left elements
    while (left <= mid) {
        count[v[left].second] += numRightSmaller;
        tmp.push_back(v[left++]);
    }

    // Remaining right elements
    while (right <= high) {
        tmp.push_back(v[right++]);
    }

    // Copy back to v
    for (int i = low; i <= high; i++) {
        v[i] = tmp[i - low];
    }
}


    void mergeSort(vector<int>& count, vector<pair<int, int>>& v, int left,
                   int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid + 1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();

        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++)
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);

        mergeSort(count, v, 0, N - 1);

        return count;
    }
};