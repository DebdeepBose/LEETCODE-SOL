class Solution {
public:
    void merge(vector<int>& count, vector<pair<int, int>>& p, int low,
               int mid, int high) {
        vector<pair<int, int>> tmp;
        int left = low;
        int right = mid + 1;
        int rc = 0;
        while (left <= mid && right <= high) {
            if (p[left].first <= p[right].first) {
                count[p[left].second] += rc;
                tmp.push_back(p[left]);
                left++;
            } else if (p[left].first > p[right].first) {
                rc++;
                tmp.push_back(p[right]);
                right++;
            }
        }
        while (left <= mid) {
            count[p[left].second] += rc;
            tmp.push_back(p[left]);
            left++;
        }
        while (right <= high) {
            tmp.push_back(p[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            p[i] = tmp[i - low];
        }
    }
    void mergeSort(vector<int>& count, vector<pair<int, int>>& p, int low,
                   int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;

        mergeSort(count, p, low, mid);
        mergeSort(count, p, mid + 1, high);
        merge(count, p, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& v) {

        int n = v.size();

        if (n == 1) {
            return {0};
        }

        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = make_pair(v[i], i);
        }

        vector<int> count(n, 0);

        mergeSort(count, p, 0, n - 1);

        return count;
    }
};