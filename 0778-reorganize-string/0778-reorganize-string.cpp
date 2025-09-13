class Solution {
public:
    string reorganizeString(string s) {

        // Our whole problem revolves around frequency of the characters
        // So obviously we need a hashmap to store these
        unordered_map<char, int> frequencyMap;

        for (char ch : s) {
            frequencyMap[ch]++;
        }

        /* Now here's what we are going to do, we will use a max heap
           and we are going to simultaneously add top 2 elements from the heap
           to our string if they exist of course, and yes our max heap would
           be structured according to frequency
        */

        // pair<int,char> because we need <frequency,character> pair
        priority_queue<pair<int, char>> maxHeap;

        for (auto pair : frequencyMap) {
            maxHeap.push({pair.second, pair.first});
        }
        // Doing so will create our max-heap

        /* Now since we are adding two elements simultaneously we need to keep
         * in check the fact that we can only run our loop until the number of
         * elements in our heap is >= 2 */

        string organizedString = "";

        while (maxHeap.size() >= 2) {

            // We are using this to store, check and pop
            auto [frequency1, character1] = maxHeap.top();
            maxHeap.pop();

            auto [frequency2, character2] = maxHeap.top();
            maxHeap.pop();

            // Now we add them to our string
            organizedString += character1;
            organizedString += character2;

            /* Since we added those into the string we consumed one of each
             * character so we need to decrease their frequency */

            frequency1--;
            frequency2--;

            /* Now in order to proceed we must check if the frequency of these
             * characters is greater than 0 or not, if yes we need to push back
             * the character since we popped it, if not then no changes */

            if (frequency1 > 0) {
                maxHeap.push({frequency1, character1});
            }
            if (frequency2 > 0) {
                maxHeap.push({frequency2, character2});
            }
        }

        /*
        Alright now there may be cases where our heap still has a character,
        like when string is "ababa", we would be left with an extra 'a'.
        But the thing is what if we had "ababaa", 2 extra 'a's,
        in that case we return "" 
        */

        if (!maxHeap.empty()) {
            auto [frequency, character] = maxHeap.top();
            if (frequency > 1) {
                return "";
            }
            organizedString += character;
        }

        return organizedString;
    }
};
