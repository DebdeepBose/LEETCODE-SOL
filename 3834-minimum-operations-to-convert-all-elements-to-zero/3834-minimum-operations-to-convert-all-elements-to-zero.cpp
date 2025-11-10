class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Yeah so we using a monotonic stack(increasing)
        // The idea is we traverse the array and if
        /*
        Stack is empty : we push the element to the stack
        Now suppose we have something like [3 1 4]
        Now we gotta understand that by the time we reach 3 (i=0),
        1 (i=1) would be already 0 so there would be a hole between 3 and 4
        so the pattern we can see is that if nums[i] < st.top(),
        we gotta keep popping the top element.So what about the popped
        element that also needs to be 0 eventually right? so all we do is when
        we are inserting an element in the stack we simply increase out
        operationCount.
        However what if we have [1 2 3]
        as u can see the array is increasing so we dont really need to pop
        anything for now we can just add it.
        Also if num[i] == 0 check if the stack is empty or if top > 0 in that
        case just push it
        */

        int n = nums.size();
        stack<int> st;
        int operationCount = 0;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[i] < st.top()) {
                st.pop();
            }

            if (nums[i] == 0) {
                if (st.empty() || st.top() > 0) {
                    st.push(0);
                }
                continue;
            }

            if (st.empty() || nums[i] > st.top()) {
                operationCount++;
                st.push(nums[i]);
            }
        }

        return operationCount;
    }
};