//Time complexity:O(n)
//Space complexity:O(k)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left=0,right=0,maxlen=0;

//loop for adding the char until we hit a repeated character
        while(right<s.length()){
            if(!window.count(s[right])){
                window.insert(s[right]);
                maxlen= max(maxlen,right-left+1);
                right++;
                //once we hit the repeated character we remove an element from the left
            }else{
                window.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};
