class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size() > n){
            return "";
        }

        unordered_map<char, int> mp;
        // variables
        for(char &ch : t)
            mp[ch]++;

        int requiredCount = t.size();
        int i = 0, j = 0;

        int minWindowSize = INT_MAX;
        int start_i = 0;

        //start
        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0)
                requiredCount--;

            mp[ch]--;

            while(requiredCount == 0){
                // start shrinking the window

                int currWindowSize = j-i+1;

                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        //till here we got our answer
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};