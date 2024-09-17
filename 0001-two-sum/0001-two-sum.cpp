class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<pair<int, int>> original_index;
        vector<int> ans;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            original_index.push_back({v[i], i});
        }
        sort(original_index.begin(), original_index.end());
        int left_p = 0;
        int right_p = n - 1;
        while (left_p < right_p) {
            int sum = original_index[left_p].first + original_index[right_p].first;
            if (sum < target) {
                left_p++;
            } 
            else if (sum > target) {
                right_p--;
            }
            else {
                ans.push_back(original_index[left_p].second);
                ans.push_back(original_index[right_p].second);
                return ans;
            }
        }
        return {};
    }
};
