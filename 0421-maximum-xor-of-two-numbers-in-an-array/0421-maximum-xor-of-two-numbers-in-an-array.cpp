class Solution {
 
    class Trie {
        struct Node {
            int val;        // bit value (0 or 1) - optional/debug
            Node* one;      // child for bit 1
            Node* zero;     // child for bit 0

            Node() {
                val = 0;
                one = nullptr;
                zero = nullptr;
            }
        };

        Node* root;

    public:
        Trie() {
            root = new Node();   // root represents empty prefix
        }

        // Insert a number into the trie (32-bit representation)
        void add(int x) {
            Node* cur = root;

            // Process from MSB (bit 31) to LSB (bit 0)
            for (int i = 31; i >= 0; i--) {
                int bit = x & (1 << i);

                if (bit != 0) {  // Bit is 1
                    if (cur->one != nullptr) {
                        cur = cur->one;
                    } else {
                        Node* nn = new Node();
                        nn->val = 1;
                        cur->one = nn;
                        cur = nn;
                    }
                } else {  // Bit is 0
                    if (cur->zero != nullptr) {
                        cur = cur->zero;
                    } else {
                        Node* nn = new Node();
                        nn->val = 0;
                        cur->zero = nn;
                        cur = nn;
                    }
                }
            }
        }

        // Find maximum XOR value with x using numbers in trie
        int maxXor(int x) {
            Node* cur = root;
            int ans = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = x & (1 << i);

                if (bit != 0) {  // Current bit of x is 1
                    // Prefer 0 (1 ^ 0 = 1)
                    if (cur->zero != nullptr) {
                        cur = cur->zero;
                        ans += (1 << i);
                    } else {
                        cur = cur->one;
                    }
                } else {  // Current bit of x is 0
                    // Prefer 1 (0 ^ 1 = 1)
                    if (cur->one != nullptr) {
                        cur = cur->one;
                        ans += (1 << i);
                    } else {
                        cur = cur->zero;
                    }
                }
            }

            return ans;  // This equals x ^ (best number in trie)
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;

        // Build trie
        for (int num : nums) {
            t.add(num);
        }

        int ans = 0;

        // Compute max XOR
        for (int num : nums) {
            ans = max(ans, t.maxXor(num));
        }

        return ans;
    }
};