class Solution {
public:
    typedef pair<int, int> p;

    int countSoldiers(vector<int>& row) {
        int low = 0, high = row.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (row[mid] == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<p> pq;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int soldiers = countSoldiers(mat[i]);
            pq.push({soldiers, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};
