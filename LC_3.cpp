// Date: 2024-07-23
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r= 0;
        unordered_map<char, int> map;
        int longestSubstr = 0;
        while (r<s.size()){
            char ch = s[r];
            if (map.find(ch) != map.end() && l <= map[ch]){ // found in mmap
                l = map[ch] + 1;
                map.erase(ch);
                //l = map[ch] + 1;
            }
            map[ch] = r;
            longestSubstr = max(longestSubstr, r-l+1);
            r++;
        }
        return longestSubstr;
    }
};


int main() {
   Solution s;
   s.lengthOfLongestSubstring("abba");
}