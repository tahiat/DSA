#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int n = s.length(); //length of the string

        int st = 0, en = 0;
        int max_str = -1;
        int map_table[256] = {0};

        while (en < n){ // as long right pointer don't reach end
            char ch = s[en];
            map_table[ch]++;
            
            if (map_table[ch] <= 1) {
                max_str = max(max_str, en-st+1);
            }
            else {
                //duplicate exists. shrink the window. the duplicated char will have 2 in table value
                while (map_table[s[st]] != 2 && st <= en) // try with removing st <= en
                {
                    map_table[s[st]] -= 1;
                    st++;
                }
                // reched the duplicate causing character position. 
                map_table[s[st]] -= 1;
                st++;    
            }

            en++;
        }
        return max_str;
}

int main() {
    int a = lengthOfLongestSubstring("pwwkew");

    cout << a;
}