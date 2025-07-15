//Time complexity:O(m+n)
//Space complexity:O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        
        //if the length of t surpasses the length of s then return blank space
        if(t.length()>n)
            return "";

            unordered_map<char,int>mp;

            for(char &ch :t)// store the value
            mp[ch]++;

            int requiredCount = t.length();
            int i=0,j=0;

            int windowSize = INT_MAX;
            int startofi=0;

             while(j<n){
                char ch=s[j];

                if(mp[ch] >0)
                requiredCount--;

                mp[ch]--;

                while(requiredCount == 0){
                    int currWindowSize =j-i+1;

                    if(windowSize > currWindowSize){
                        windowSize = currWindowSize;
                        startofi =i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] >0){
                        requiredCount ++;
                    }
                    i++;
                }
                j++;
             }
        return windowSize == INT_MAX ? "": s.substr(startofi,windowSize );
    }
};
