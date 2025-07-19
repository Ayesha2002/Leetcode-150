//Time complexity:O(n)
//Space complexity:O(1)
//Optimal approach by hashing
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int freq : count)
            if (freq != 0) return false;

        return true;
    }
};

//basic we can code it as
// sort(begin(s),end(s));
// sort(begin(t),end(t));
//return s== t;
//Time complexity:O(nlogn)
//Space complexity:O(1)
