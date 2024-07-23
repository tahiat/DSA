// Date: 2024-07-21
// Description: 

#include <iostream>
using namespace std;

int arr[5] = {0};

void permute(int i ){
    if (i == 3){
        for (int i = 0; i< 3; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    arr[i] = 0;
    permute(i+1);
    arr[i]= 1;
    permute(i+1);
}


int main() {
    permute(0);
} 