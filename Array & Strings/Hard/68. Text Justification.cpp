//Greedy method
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;

            // Try to fit as many words as possible into the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length(); // 1 for space
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength + (numWords - 1); // space to fill

            string line;

            // Case 1: Last line OR line with only 1 word → left-justified
            if (j == n || numWords == 1) {
                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    line += ' ';
                    line += words[k];
                }
                // Fill remaining spaces at the end
                line += string(maxWidth - line.length(), ' ');
            }
            // Case 2: Fully justified
            else {
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j - 1; ++k) {
                    line += words[k];
                    line += string(spaceBetween + (k - i < extraSpaces ? 1 : 0), ' ');
                }
                line += words[j - 1]; // last word, no space after
            }

            result.push_back(line);
            i = j; // move to next group
        }

        return result;
    }
};
