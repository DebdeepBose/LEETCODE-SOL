class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++) {
            int current_element = v[i];
            int leftover = target - current_element;
            auto it = mp.find(leftover);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[current_element] = i;
        }
        return {};
    }
};