//Time complexity:O(n+m) n=ransomNote and m=magazine
//Space complexity:O(1) for fixed letters 26
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqRansom(26, 0);
        vector<int> freqMag(26, 0);

        for (char ch : ransomNote)
            freqRansom[ch - 'a']++;

        for (char ch : magazine)
            freqMag[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freqRansom[i] > freqMag[i])
                return false;
        }

        return true;
    }
};
