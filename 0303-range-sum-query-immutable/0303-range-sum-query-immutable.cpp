class NumArray {
public:
    vector<int> pref;

    NumArray(vector<int>& v) {
        int n = v.size();
        pref.push_back(v[0]);
        for (int i = 1; i < n; i++) {
            pref.push_back(v[i] + pref[i - 1]);
        }
    }

    int sumRange(int left, int right) {
        return (left == 0) ? pref[right] : pref[right] - pref[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */