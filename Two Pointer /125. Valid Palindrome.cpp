

//Time complexity:O(n)
//Space Complexity:O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;//characters from the left
        int right = s.length() - 1;//characters from the right

        while (left < right)//continue checking elements from both sides until they meet inthe middle.
         {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
