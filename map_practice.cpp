#include<iostream>
#include<unordered_map>
using namespace std;

int main () {
    unordered_map<char, int> test;

    test['m'] = 10;
    test['n'] = 30;
    test['g'] = 60;

    cout << "value of test size " << test.size() << endl; 
    for (int i = 0; i<test.size(); i++){ // wrong;;
        cout << test[i] << endl;
    }
}