class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode slow = head;
        ListNode fast = head;
        for (int i = 1; i < k; i++) {
            fast = fast.next;
        }
        ListNode tmpFast = fast;
        while(tmpFast.next != null){
            slow = slow.next;
            tmpFast = tmpFast.next;
        } 

        int a = fast.val;
        int b = slow.val;

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        fast.val = a;
        slow.val = b;

        return head;
    }
}
