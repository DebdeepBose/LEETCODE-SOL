class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        while (head && st.count(head->val)) {
            head = head->next;
        }
        ListNode* tmp = head;
        while (head && head->next) {
            if (st.count(head->next->val)) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return tmp;
    }
};
