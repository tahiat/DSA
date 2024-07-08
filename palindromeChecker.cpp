#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str, int s, int e){
        while (s < e){
            if (str[s] != str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
}

int main() {

}