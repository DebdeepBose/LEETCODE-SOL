class Solution {
public:
    int merge(vector<int>& v, int low, int mid, int high) {
        int rc = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)v[i] > 2LL * v[j]) {
                j++;
            }
            rc += (j - (mid + 1));
        }

        vector<int> tmp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (v[left] <= v[right]) {
                tmp.push_back(v[left++]);
            } else {
                tmp.push_back(v[right++]);
            }
        }
        while (left <= mid) {
            tmp.push_back(v[left++]);
        }
        while (right <= high) {
            tmp.push_back(v[right++]);
        }

        for (int i = low; i <= high; i++) {
            v[i] = tmp[i - low];
        }

        return rc;
    }

    int mergeSort(vector<int>& v, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        int c = 0;
        c += mergeSort(v, low, mid);
        c += mergeSort(v, mid + 1, high);
        c += merge(v, low, mid, high);
        return c;
    }

    int reversePairs(vector<int>& v) {
        return mergeSort(v, 0, v.size() - 1);
    }
};
