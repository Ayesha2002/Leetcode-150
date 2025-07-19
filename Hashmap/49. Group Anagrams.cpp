class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>mpp;
        for(string s:strs){
            string sorted_s=s;
            sort(sorted_s.begin(),sorted_s.end());
            mpp[sorted_s].push_back(s);
        }

        for(auto &pair : mpp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
