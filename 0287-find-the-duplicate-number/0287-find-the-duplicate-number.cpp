class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int fast = 0;
        int slow = 0;
        int n = v.size();
        
        do {
            slow = v[slow];
            fast = v[v[fast]];
        } while (slow != fast);
        
        slow = 0;
        while (slow != fast) {
            slow = v[slow];
            fast = v[fast];
        }
        
        return slow;
    }
};
