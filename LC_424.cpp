// Date: 2024-07-23
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:

    bool hasCoveredT(unordered_map<char, int>& freq){
        for (auto pair : freq){
            if (pair.second != 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if (lenT > lenS) return "";

        int l = 0; // left pointer of the window
        unordered_map<char, int> freq;
        for (char c: t){
            freq[c]++;
        }
        string result = "";
        unordered_map<char, int> freqCopy(freq);
        for(int r = 0; r < lenS; r++){   
            char ch = s[r];

            if (freqCopy.find(ch) != freqCopy.end() && !hasCoveredT(freqCopy)){
                freqCopy[ch]--;
            }
            // check if current window has covered all of t; how to check? check if all key value of freqcopy is 0
            if (hasCoveredT(freqCopy)){
                // shrink the window by increasing l, as long as s[l] not in t;

                while (freqCopy.find(s[l]) != freqCopy.end()){
                    l++;
                }
                result = s.substr(l, r-l+1);
            }
        }

        return result;
    }
};

int main() {
    Solution sln;
    if (sln.minWindow("ADOBECODEBANC", "ABC") != "BANC" ) {
        cout << "wrong result for Test case 1" << endl;
    }

    if (sln.minWindow("a", "a") != "a" ) {
        cout << "wrong result for Test case 2" << endl;
    } 

    if (sln.minWindow("a", "aa") != "" ) {
        cout << "wrong result for Test case 3" << endl;
    } 

    return 0;
}