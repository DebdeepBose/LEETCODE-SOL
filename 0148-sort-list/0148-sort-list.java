/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }

        List<Integer> l = new ArrayList<>();
        ListNode tmp = head;
        while(tmp != null){
            l.add(tmp.val);
            tmp = tmp.next;
        }

        Collections.sort(l);

        tmp = head;
        for(int i = 0; i < l.size(); i++){
            tmp.val = l.get(i);
            tmp = tmp.next;
        }

        return head;
    }
}
