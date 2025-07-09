// It a Greedy two passes approach, bacause :
//- initailize, first pass(L2R), second pass(R2L), lastly count the candies
//Time complexity:O(n)
//Space Complexity:O(n)//due to the count vector if made two vectore L2r and R2L space would have become O(n2)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);  // Each child gets at least 1 candy

        // Left to right pass
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        // Right to left pass
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                count[i] = max(count[i], count[i + 1] + 1);
            }
        }

        // Sum up the total candies
        int result = 0;
        for(int i = 0; i < n; i++) {
            result += count[i];
        }

        return result;
    }
};
