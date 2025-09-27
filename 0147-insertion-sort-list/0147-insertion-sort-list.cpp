/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        vector<int> v;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }

        sort(v.begin(), v.end());

        tmp = head;
        for (int i = 0; i < v.size(); i++) {
            tmp->val = v[i];
            tmp = tmp->next;
        }

        return head;
    }
};