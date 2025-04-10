class Solution {
public:
    vector<int> count; // To store the result
    vector<int> index; // To keep track of original indices

    // Merge function (your style, fixed)
    void merge(vector<int>& v, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> tmpIndex;
        vector<int> tmpValue;
        int rightCount = 0;

        while (left <= mid && right <= high) {
            if (v[index[right]] < v[index[left]]) {
                tmpIndex.push_back(index[right]);
                rightCount++;
                right++;
            } else {
                count[index[left]] += rightCount;
                tmpIndex.push_back(index[left]);
                left++;
            }
        }

        while (left <= mid) {
            count[index[left]] += rightCount;
            tmpIndex.push_back(index[left]);
            left++;
        }

        while (right <= high) {
            tmpIndex.push_back(index[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            index[i] = tmpIndex[i - low];
        }
    }

    // Merge Sort (your style)
    void mS(vector<int>& v, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mS(v, low, mid);
        mS(v, mid + 1, high);
        merge(v, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        count.resize(n, 0);
        index.resize(n);

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        mS(v, 0, n - 1);
        return count;
    }
};
