/*Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> anagram;
        map<string,vector<string>> dictonary;
        
        for(string a : strs)
        {
            string b = a;
            sort(a.begin(),a.end());
            dictonary[a].push_back(b);
        }
        
        for(auto i = dictonary.begin() ; i!= dictonary.end();i++)
        {
            anagram.push_back(i->second);  //here i am specifying i->second because we finally want the value to be printed..if we wanted key it would be i->first.
        }
        
        return anagram;
    }
};
