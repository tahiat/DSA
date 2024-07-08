#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(int x) {
    vector<int> num_list;

    if (x < 0) return false;

    while (x >= 0){
        int digit = x % 10;
        num_list.push_back(digit);
        x = x / 10;
    } 

    int num_of_digit = num_list.size();

    int i = 0, j = num_of_digit - 1;

    while (i < j){
        if (num_list[i] != num_list[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    cout << "121 is palindrome " <<  endl;
    
    return 0;
}
