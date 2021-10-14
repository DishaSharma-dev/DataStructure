class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return " ";
        int minLengthPrefix = INT_MAX;
        int index = 0;
        for(int i = 0; i < strs.size(); i++) {
            if(minLengthPrefix > strs[i].length()) {
                minLengthPrefix = strs[i].length();
                index = i;
            }
        }
        string prefix = strs[index];
        for(string str : strs) {
            int i = 0;
            int j = 0;
            int count = 0;
            while(i < str.length() && j < prefix.length() && str[i] == prefix[j]) {
                i++;
                j++;
                count++;
            }
            prefix = prefix.substr(0,count);
        }
       return prefix; 
    }
};