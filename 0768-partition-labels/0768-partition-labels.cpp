class Solution {
public:
    vector<int> partitionLabels(string s) {

        //Taking the length of the string
        int n = s.size(); 

        // Store last occurrence of each character
        unordered_map<char, int> mp; 

        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        // Previous partition end
        int prev = -1; 

        // Max last occurrence in current partition
        int maxi = 0; 

         // Stores partition sizes
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Update max last occurrence
            maxi = max(maxi, mp[s[i]]); 
            
            // If end of partition reached
            if (maxi == i) { 

                // Store partition size
                ans.push_back(maxi - prev);

                // Update previous partition end 
                prev = maxi; 
            }
        }

        //Return the vector
        return ans; 
    }
};
