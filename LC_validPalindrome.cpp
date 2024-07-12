#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); ){
            if (!((s[i] >= 'a' && s[i] <='z') || (s[i]>='A' && s[i]<='Z') || (s[i] >= '0' && s[i] <= '9'))){
                s.erase(i,1);
            }
            else {
                if (s[i] >= 'A' && s[i] <= 'Z'){
                    s[i] = tolower(s[i]);
                }
                i++;
            } 
        }

        int l = 0, r = s.size()-1;

        while (l< r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
}
int main (){
    isPalindrome("Was it a car or a cat I saw?");
}