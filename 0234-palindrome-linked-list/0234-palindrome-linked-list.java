class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slowPointer = head;
        ListNode fastPointer = head;

        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;
            slowPointer = slowPointer.next;
        }

        ListNode previousNode = null;

        while (slowPointer != null) {
            ListNode nextNode = slowPointer.next;
            slowPointer.next = previousNode;
            previousNode = slowPointer;
            slowPointer = nextNode;
        }

        ListNode left = head;
        ListNode right = previousNode;
        
        while(right != null){
            if(left.val != right.val){
                return false;
            }
            left = left.next;
            right = right.next;
        }
    return true;
    }
}
